"""
Mina/o1js backend core testing logic.

This module implements the main metamorphic testing pipeline for Mina/o1js circuits.
"""

from pathlib import Path
from random import Random
import time

from circuzz.common.metamorphism import MetamorphicCircuitPair
from circuzz.common.helper import generate_metamorphic_related_circuit
from circuzz.common.field import CurvePrime, get_curve_name
from circuzz.common.helper import generate_random_circuit
from circuzz.common.helper import random_weighted_metamorphic_kind
from circuzz.common.colorlogs import get_color_logger

from experiment.config import Config, OnlineTuning
from experiment.data import DataEntry, TestResult

from .helper import run_metamorphic_tests

logger = get_color_logger()


def save_error_metamorphic_circuit_pair(
    save_path: Path,
    mina_code: str,
    mina_code_tf: str,
):
    """
    Save error circuit pair to disk for inspection.
    
    Args:
        save_path: Base directory for saving errors
        mina_code: Original Mina/o1js code
        mina_code_tf: Transformed Mina/o1js code
    """
    error_dir = save_path / "errors"
    
    num_of_subdirs = len(list(error_dir.glob("error_*")))
    current_error_dir = error_dir / f"error_{num_of_subdirs + 1}"
    current_error_dir.mkdir(parents=True, exist_ok=True)
    
    with open(current_error_dir / "circuit.ts", "w") as f:
        f.write(mina_code)
    with open(current_error_dir / "circuit_transformed.ts", "w") as f:
        f.write(mina_code_tf)


def run_mina_metamorphic_tests(
    seed: float,
    working_dir: Path,
    report_dir: Path,
    config: Config,
    online_tuning: OnlineTuning,
) -> TestResult:
    """
    Run a single metamorphic test with a given seed.
    
    Args:
        seed: Random seed for test generation
        working_dir: Working directory for test execution
        report_dir: Directory for saving error reports
        config: Test configuration
        online_tuning: Online tuning parameters
    
    Returns:
        TestResult with all test iterations and metadata
    """
    start_time = time.time()
    logger.info(f"mina metamorphic testing, seed: {seed}, working-dir: {working_dir}")
    
    rng = Random(seed)
    ir_gen_seed = rng.randint(1000000000, 9999999999)
    ir_tf_seed = rng.randint(1000000000, 9999999999)
    test_seed = rng.randint(1000000000, 9999999999)
    kind = random_weighted_metamorphic_kind(rng, config.ir.rewrite.weakening_probability)
    
    # TODO: Determine which curves Mina/o1js supports
    # For now, use BN254 as a placeholder (similar to Noir)
    curve_prime = CurvePrime.BN254
    curve_name = get_curve_name(curve_prime)
    
    # Generate original circuit
    ir_generation_start = time.time()
    ir = generate_random_circuit(curve_prime, True, config.ir, ir_gen_seed)
    ir.name = f"Circuit_{curve_name}"
    ir_generation_time = time.time() - ir_generation_start
    
    # Apply metamorphic transformation
    ir_rewrite_start = time.time()
    POIs, ir_tf = generate_metamorphic_related_circuit(kind, ir, curve_prime, config.ir, ir_tf_seed)
    postfix = "_eq" if kind.value == "equal" else "_wk"
    ir_tf.name = f"{ir.name}{postfix}"
    ir_rewrite_time = time.time() - ir_rewrite_start
    
    # Create metamorphic pair and run tests
    metamorphic_pair = MetamorphicCircuitPair(kind, ir, ir_tf, POIs)
    mina_result = run_metamorphic_tests(
        metamorphic_pair,
        test_seed,
        curve_prime,
        working_dir,
        config,
        online_tuning,
    )
    test_time = time.time() - start_time
    
    # Save circuits if error detected
    has_error = any(iteration.error is not None for iteration in mina_result.iterations)
    if has_error and mina_result.original_code and mina_result.transformed_code:
        save_error_metamorphic_circuit_pair(report_dir, mina_result.original_code, mina_result.transformed_code)
    
    # Create data entries for each iteration
    data_entries: list[DataEntry] = []
    for idx, iteration in enumerate(mina_result.iterations):
        data_entry = DataEntry(
            tool="mina",
            test_time=test_time,
            seed=seed,
            curve=curve_name,
            oracle=kind.value,
            iteration=idx,
            error=iteration.error,
            ir_generation_seed=ir_gen_seed,
            ir_generation_time=ir_generation_time,
            ir_rewrite_seed=ir_tf_seed,
            ir_rewrite_time=ir_rewrite_time,
            ir_rewrite_rules=[POI.rule.name for POI in POIs],
            c1_node_size=ir.node_size(),
            c1_assignments=len(ir.assignments()),
            c1_assertions=len(ir.assertions()),
            c1_assumptions=len(ir.assumptions()),
            c1_input_signals=len(ir.inputs),
            c1_output_signals=len(ir.outputs),
            c2_node_size=ir_tf.node_size(),
            c2_assignments=len(ir_tf.assignments()),
            c2_assertions=len(ir_tf.assertions()),
            c2_assumptions=len(ir_tf.assumptions()),
            c2_input_signals=len(ir_tf.inputs),
            c2_output_signals=len(ir_tf.outputs),
        )
        data_entries.append(data_entry)
    
    return TestResult(
        tool="mina",
        iterations=mina_result.iterations,
        data_entries=data_entries,
        original_code=mina_result.original_code,
        transformed_code=mina_result.transformed_code,
    )
