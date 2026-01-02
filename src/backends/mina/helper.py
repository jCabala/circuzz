"""
Mina/o1js metamorphic testing helpers.

This module contains utilities for running metamorphic tests on Mina/o1js circuits.
"""

from dataclasses import dataclass
from enum import StrEnum
from pathlib import Path
from random import Random

from circuzz.common.field import CurvePrime, random_field_element
from circuzz.common.metamorphism import MetamorphicCircuitPair
from circuzz.common.colorlogs import get_color_logger
from circuzz.ir.nodes import Circuit

from experiment.config import Config, OnlineTuning
from experiment.data import TestResult, TestIteration

from .ir2mina import IR2MinaVisitor
from .emitter import EmitVisitor
from .command import run_o1js_test, run_o1js_prove, run_o1js_verify

logger = get_color_logger()


class MinaError(StrEnum):
    """Possible error types detected by Mina tests."""
    UNKNOWN_EXECUTION_ERROR = "unknown execution error"
    UNKNOWN_PROOF_ERROR = "unknown proof error"
    UNKNOWN_VERIFICATION_ERROR = "unknown verification error"
    
    DIVERGING_SIGNALS = "diverging signals"
    METAMORPHIC_VIOLATION = "metamorphic violation"


@dataclass
class TestIteration:
    """Represents a single test iteration with timing and error info."""
    c1_execute: bool | None = None
    c1_execute_time: float | None = None
    c2_execute: bool | None = None
    c2_execute_time: float | None = None
    
    c1_prove: bool | None = None
    c1_prove_time: float | None = None
    c2_prove: bool | None = None
    c2_prove_time: float | None = None
    
    c1_verify: bool | None = None
    c1_verify_time: float | None = None
    c2_verify: bool | None = None
    c2_verify_time: float | None = None
    
    error: MinaError | None = None


def ir_to_mina_code(ir: Circuit, curve: CurvePrime) -> str:
    """
    Convert IR circuit to Mina/o1js TypeScript code.
    
    Args:
        ir: Intermediate representation of circuit
        curve: Field curve for the circuit
    
    Returns:
        TypeScript source code for Mina ZkProgram
    """
    # TODO: Implement IR to Mina transformation
    # This should:
    # 1. Create IR2MinaVisitor with the curve
    # 2. Transform the circuit
    # 3. Emit the resulting AST to code
    raise NotImplementedError("ir_to_mina_code not yet implemented")


def run_metamorphic_tests(
    metamorphic_pair: MetamorphicCircuitPair,
    test_seed: int,
    curve: CurvePrime,
    working_dir: Path,
    config: Config,
    online_tuning: OnlineTuning,
) -> TestResult:
    """
    Run metamorphic tests on a circuit pair.
    
    Args:
        metamorphic_pair: Original and transformed circuit pair
        test_seed: Seed for test input generation
        curve: Field curve for the circuits
        working_dir: Directory for test execution
        config: Test configuration
        online_tuning: Online tuning parameters
    
    Returns:
        TestResult with test iterations and results
    """
    # TODO: Implement metamorphic testing
    # This should:
    # 1. Generate test inputs using test_seed
    # 2. Execute both circuits
    # 3. Compare results
    # 4. Detect metamorphic violations
    # 5. Return TestResult with all iterations
    raise NotImplementedError("run_metamorphic_tests not yet implemented")
