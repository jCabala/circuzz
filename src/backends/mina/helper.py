"""
Mina/o1js metamorphic testing helpers.

This module contains utilities for running metamorphic tests on Mina/o1js circuits.
"""

from dataclasses import dataclass, field
from enum import StrEnum
from pathlib import Path
from random import Random
from typing import TYPE_CHECKING
import re
import json

from circuzz.common.command import ExecStatus, execute_command
from circuzz.common.field import CurvePrime, random_field_element
from circuzz.common.filesystem import clean_or_create_dir
from circuzz.common.helper import remove_ansi_escape_sequences
from circuzz.common.metamorphism import MetamorphicCircuitPair
from circuzz.common.colorlogs import get_color_logger
from circuzz.ir.nodes import Circuit

from .ir2mina import IR2MinaVisitor
from .emitter import EmitVisitor
from .config import MinaConfig

if TYPE_CHECKING:
    from experiment.config import OnlineTuning

logger = get_color_logger()

# ================================================================
#                        Constants
# ================================================================

PROJECT_NAME = "circuit"
CIRCUIT_FILENAME = "circuit.ts"
COMPILED_FILENAME = "circuit.js"

# ================================================================
#                        Error Types
# ================================================================


class MinaError(StrEnum):
    """Possible error types detected by Mina tests."""
    DIVERGING_SIGNALS = "diverging signals"
    METAMORPHIC_VIOLATION_EXECUTION = "metamorphic violation execution"


# ================================================================
#                        Result Types
# ================================================================


@dataclass
class TestIteration:
    """Represents a single test iteration with timing and error info."""
    # TypeScript compilation (tsc)
    c1_ts_compile: bool | None = None
    c1_ts_compile_time: float | None = None
    c2_ts_compile: bool | None = None
    c2_ts_compile_time: float | None = None
    
    # ZkProgram compilation (circuit.compile())
    c1_zk_compile: bool | None = None
    c1_zk_compile_time: float | None = None
    c2_zk_compile: bool | None = None
    c2_zk_compile_time: float | None = None
    
    # Proving (circuit.compute())
    c1_prove: bool | None = None
    c1_prove_time: float | None = None
    c2_prove: bool | None = None
    c2_prove_time: float | None = None
    
    # Verification
    c1_verify: bool | None = None
    c1_verify_time: float | None = None
    c2_verify: bool | None = None
    c2_verify_time: float | None = None
    
    # Output values
    c1_output: str | None = None
    c2_output: str | None = None
    
    # Ignored errors (known issues)
    c1_ignored_error: str | None = None
    c2_ignored_error: str | None = None
    
    # Stopping error
    error: str | None = None
    
    def is_error(self) -> bool:
        return self.error is not None


@dataclass
class MinaResult:
    """Result of running Mina metamorphic tests."""
    iterations: list[TestIteration] = field(default_factory=list)
    original_code: str | None = None
    transformed_code: str | None = None


# ================================================================
#                     Input Generation
# ================================================================


def random_input(
    input_signals: list[str],
    input_types: list[str],
    curve: CurvePrime,
    boundary_probability: float,
    rng: Random,
) -> dict[str, str]:
    """
    Generate random inputs for a circuit.
    
    Args:
        input_signals: List of input signal names
        input_types: List of input types ("Field" or "Bool")
        curve: Field curve for generating field elements
        boundary_probability: Probability of choosing boundary values
        rng: Random number generator
    
    Returns:
        Dictionary mapping signal names to string values
    """
    input_map: dict[str, str] = {}
    
    for name, typ in zip(input_signals, input_types):
        if typ == "Bool":
            # Boolean: randomly true or false
            input_map[name] = "true" if rng.random() < 0.5 else "false"
        else:
            # Field: use random_field_element with boundary probability
            value = random_field_element(
                curve, rng, 
                exclude_prime=True,
                boundary_prob=boundary_probability
            )
            input_map[name] = str(value)
    
    return input_map


# ================================================================
#                     Code Generation
# ================================================================


def ir_to_mina_code(
    circuit: Circuit, 
    curve: CurvePrime,
    is_boolean_circuit: bool = False,
) -> str:
    """
    Convert IR circuit to Mina/o1js TypeScript code.
    
    Args:
        circuit: Intermediate representation of circuit
        curve: Field curve for the circuit
        is_boolean_circuit: Whether to use Bool type for all signals
    
    Returns:
        TypeScript source code for Mina ZkProgram
    """
    visitor = IR2MinaVisitor(curve, is_boolean_circuit=is_boolean_circuit)
    ast = visitor.transform(circuit)
    emitter = EmitVisitor()
    return emitter.emit(ast)


# ================================================================
#                     Project Setup
# ================================================================


def create_package_json(project_dir: Path) -> Path:
    """Create package.json for o1js project."""
    package_json = {
        "name": "circuit-test",
        "version": "1.0.0",
        "type": "module",
        "scripts": {
            "build": "tsc",
            "test": "node --experimental-vm-modules test-runner.mjs"
        },
        "dependencies": {
            "o1js": "^2.2.0"
        },
        "devDependencies": {
            "typescript": "^5.7.0"
        }
    }
    
    path = project_dir / "package.json"
    path.write_text(json.dumps(package_json, indent=2))
    return path


def create_tsconfig(project_dir: Path) -> Path:
    """Create tsconfig.json for TypeScript compilation."""
    tsconfig = {
        "compilerOptions": {
            "target": "ESNext",
            "module": "ESNext",
            "moduleResolution": "bundler",
            "strict": True,
            "esModuleInterop": True,
            "skipLibCheck": True,
            "resolveJsonModule": True,
            "declaration": False,
            "sourceMap": False,
            "outDir": "."
        },
        "include": ["*.ts"],
        "exclude": ["node_modules"]
    }
    
    path = project_dir / "tsconfig.json"
    path.write_text(json.dumps(tsconfig, indent=2))
    return path


# ================================================================
#                  Stage-Based Test Runners
# ================================================================

COMPILE_RUNNER_FILENAME = "compile-runner.mjs"
PROVE_RUNNER_FILENAME = "prove-runner.mjs"
VERIFY_RUNNER_FILENAME = "verify-runner.mjs"
VK_FILENAME = "verification-key.json"
PROOF_FILENAME = "proof.json"


def create_compile_runner(project_dir: Path, circuit_name: str) -> Path:
    """
    Create a runner that only compiles the ZkProgram.
    Outputs verification key to verification-key.json.
    """
    runner_code = f'''// Stage 1: Compile ZkProgram
import {{ circuit }} from './{circuit_name}.js';
import fs from 'fs';

async function main() {{
    try {{
        const startTime = Date.now();
        const {{ verificationKey }} = await circuit.compile();
        const elapsedTime = Date.now() - startTime;
        
        // Save verification key
        fs.writeFileSync('{VK_FILENAME}', JSON.stringify(verificationKey, null, 2));
        
        console.log(JSON.stringify({{
            success: true,
            stage: "compile",
            time_ms: elapsedTime
        }}));
    }} catch (error) {{
        console.log(JSON.stringify({{
            success: false,
            stage: "compile",
            error: error.message
        }}));
        process.exit(1);
    }}
}}

main();
'''
    path = project_dir / COMPILE_RUNNER_FILENAME
    path.write_text(runner_code)
    return path


def create_prove_runner(
    project_dir: Path,
    circuit_name: str,
    inputs: dict[str, str],
    input_types: list[str],
) -> Path:
    """
    Create a runner that proves the circuit with given inputs.
    Requires verification key from compile stage.
    Outputs proof to proof.json.
    """
    # Build input arguments with correct types
    input_args = []
    for i, (name, value) in enumerate(sorted(inputs.items())):
        typ = input_types[i] if i < len(input_types) else "Field"
        if typ == "Bool":
            input_args.append(f"Bool({value})")
        else:
            input_args.append(f"Field({value}n)")
    
    inputs_str = ", ".join(input_args)
    
    runner_code = f'''// Stage 2: Prove circuit
import {{ Field, Bool }} from 'o1js';
import {{ circuit }} from './{circuit_name}.js';
import fs from 'fs';

async function main() {{
    try {{
        // Load verification key (ensures circuit is compiled)
        if (!fs.existsSync('{VK_FILENAME}')) {{
            throw new Error('Verification key not found. Run compile stage first.');
        }}
        
        const startTime = Date.now();
        const result = await circuit.compute({inputs_str});
        const elapsedTime = Date.now() - startTime;
        
        // Extract public output
        let outputStr;
        if (result.publicOutput === undefined) {{
            outputStr = null;
        }} else if (typeof result.publicOutput.toString === 'function') {{
            outputStr = result.publicOutput.toString();
        }} else {{
            outputStr = JSON.stringify(result.publicOutput);
        }}
        
        // Save proof
        const proofJson = result.proof.toJSON();
        fs.writeFileSync('{PROOF_FILENAME}', JSON.stringify({{
            proof: proofJson,
            publicOutput: outputStr
        }}, null, 2));
        
        console.log(JSON.stringify({{
            success: true,
            stage: "prove",
            time_ms: elapsedTime,
            public_output: outputStr
        }}));
    }} catch (error) {{
        console.log(JSON.stringify({{
            success: false,
            stage: "prove",
            error: error.message
        }}));
        process.exit(1);
    }}
}}

main();
'''
    path = project_dir / PROVE_RUNNER_FILENAME
    path.write_text(runner_code)
    return path


def create_verify_runner(project_dir: Path, circuit_name: str) -> Path:
    """
    Create a runner that verifies a proof.
    Requires proof.json and verification-key.json from previous stages.
    """
    runner_code = f'''// Stage 3: Verify proof
import {{ verify }} from 'o1js';
import {{ circuit }} from './{circuit_name}.js';
import fs from 'fs';

async function main() {{
    try {{
        // Load verification key
        if (!fs.existsSync('{VK_FILENAME}')) {{
            throw new Error('Verification key not found. Run compile stage first.');
        }}
        const vkData = JSON.parse(fs.readFileSync('{VK_FILENAME}', 'utf-8'));
        
        // Load proof
        if (!fs.existsSync('{PROOF_FILENAME}')) {{
            throw new Error('Proof not found. Run prove stage first.');
        }}
        const proofData = JSON.parse(fs.readFileSync('{PROOF_FILENAME}', 'utf-8'));
        
        const startTime = Date.now();
        const isValid = await verify(proofData.proof, vkData);
        const elapsedTime = Date.now() - startTime;
        
        console.log(JSON.stringify({{
            success: isValid,
            stage: "verify",
            time_ms: elapsedTime,
            verified: isValid
        }}));
        
        if (!isValid) {{
            process.exit(1);
        }}
    }} catch (error) {{
        console.log(JSON.stringify({{
            success: false,
            stage: "verify",
            error: error.message
        }}));
        process.exit(1);
    }}
}}

main();
'''
    path = project_dir / VERIFY_RUNNER_FILENAME
    path.write_text(runner_code)
    return path


def prepare_project(
    root: Path,
    prefix: str,
    circuit: Circuit,
    curve: CurvePrime,
    is_boolean_circuit: bool = False,
) -> tuple[Path, str]:
    """
    Create a complete o1js project for a circuit.
    
    Args:
        root: Root directory for projects
        prefix: Prefix for project directory name
        circuit: Circuit to generate code for
        curve: Field curve
        is_boolean_circuit: Whether this is a boolean circuit
    
    Returns:
        Tuple of (project_path, generated_code)
    """
    # Create project directory
    project_dir = root / f"{prefix}_{circuit.name}"
    clean_or_create_dir(project_dir)
    
    # Generate circuit code
    code = ir_to_mina_code(circuit, curve, is_boolean_circuit)
    
    # Write circuit file
    circuit_path = project_dir / CIRCUIT_FILENAME
    circuit_path.write_text(code)
    
    # Create project files
    create_package_json(project_dir)
    create_tsconfig(project_dir)
    
    # Symlink to preinstalled node_modules (from Docker image)
    # This avoids running npm install for every circuit
    preinstalled_node_modules = Path("/circuzz/programs-mina/node_modules")
    target_node_modules = project_dir / "node_modules"
    if preinstalled_node_modules.exists() and not target_node_modules.exists():
        target_node_modules.symlink_to(preinstalled_node_modules)
    
    return project_dir, code


# ================================================================
#                     Command Execution
# ================================================================


def compile_typescript(
    project_dir: Path,
    timeout: float | None = None,
) -> ExecStatus:
    """
    Compile TypeScript circuit to JavaScript.
    
    Args:
        project_dir: Directory containing the TypeScript files
        timeout: Optional timeout in seconds
    
    Returns:
        ExecStatus with compilation result
    """
    command = ["npx", "tsc", "--noEmit", "false"]
    status = execute_command(
        command,
        identifier="tsc_compile",
        working_dir=project_dir,
        timeout=timeout,
    )
    
    if status.is_failure():
        # TypeScript errors typically go to stdout, not stderr
        error_output = status.stdout or status.stderr
        logger.debug(f"TypeScript compilation failed in {project_dir}:")
        logger.debug(f"  stdout: {status.stdout[:500] if status.stdout else '(empty)'}")
        logger.debug(f"  stderr: {status.stderr[:500] if status.stderr else '(empty)'}")
    else:
        logger.debug(f"TypeScript compilation succeeded in {project_dir}")
    
    return status


# ================================================================
#                     Result Parsing
# ================================================================


def extract_assertion_error(error_msg: str) -> str | None:
    """
    Extract assertion error message from o1js output.
    
    Args:
        error_msg: Raw error message from stderr
    
    Returns:
        Extracted assertion message or None
    """
    # Check for Bool.assertTrue failure
    if "Bool.assertTrue()" in error_msg:
        return "assertion failed: Bool.assertTrue()"
    
    # Check for constraint unsatisfied
    if "Constraint unsatisfied" in error_msg:
        match = re.search(r"Constraint unsatisfied.*?:(.*?)(?:\n|$)", error_msg, re.DOTALL)
        if match:
            return f"constraint unsatisfied: {match.group(1).strip()[:100]}"
        return "constraint unsatisfied"
    
    # Check for general error
    if "Error:" in error_msg:
        match = re.search(r"Error:\s*(.+?)(?:\n|$)", error_msg)
        if match:
            return match.group(1).strip()[:200]
    
    return None


# ================================================================
#                  Stage-Based Execution Functions
# ================================================================


def run_stage_runner(
    project_dir: Path,
    runner_filename: str,
    timeout: float | None = None,
) -> ExecStatus:
    """
    Run a stage-specific runner script.
    
    Args:
        project_dir: Directory containing the runner
        runner_filename: Name of the runner file
        timeout: Optional timeout in seconds
    
    Returns:
        ExecStatus with execution result
    """
    command = ["node", "--experimental-vm-modules", runner_filename]
    return execute_command(
        command,
        identifier=f"node_{runner_filename}",
        working_dir=project_dir,
        timeout=timeout,
    )


def parse_stage_result(status: ExecStatus) -> tuple[bool, dict | None, str | None]:
    """
    Parse the result of a stage execution.
    
    Args:
        status: ExecStatus from running stage runner
    
    Returns:
        Tuple of (success, result_dict, error_message)
    """
    if status.is_timeout:
        return False, None, "timeout"
    
    stdout = status.stdout.strip()
    
    try:
        # Find JSON in output
        for line in stdout.split('\n'):
            line = line.strip()
            if line.startswith('{') and line.endswith('}'):
                result = json.loads(line)
                if result.get("success"):
                    return True, result, None
                else:
                    return False, result, result.get("error", "unknown error")
    except json.JSONDecodeError:
        pass
    
    # Fallback: check return code
    if status.returncode == 0:
        return True, None, None
    
    # Try to extract error
    stderr = remove_ansi_escape_sequences(status.stderr)
    stdout_clean = remove_ansi_escape_sequences(status.stdout)
    error_msg = extract_assertion_error(stderr) or extract_assertion_error(stdout_clean) or "stage failed"
    return False, None, error_msg


def execute_ts_compile(
    project_dir: Path,
    timeout: float | None = 60.0,
) -> tuple[bool, float | None, str | None]:
    """
    Stage 0: Compile TypeScript to JavaScript.
    
    Args:
        project_dir: Project directory with TypeScript files
        timeout: Compilation timeout
    
    Returns:
        Tuple of (success, compile_time, error_message)
    """
    compiled_file = project_dir / COMPILED_FILENAME
    if compiled_file.exists():
        logger.debug(f"Reusing compiled TypeScript in {project_dir}")
        return True, 0.0, None
    
    logger.debug(f"Compiling TypeScript in {project_dir}...")
    status = compile_typescript(project_dir, timeout=timeout)
    
    if status.is_failure():
        error_output = status.stdout.strip() or status.stderr.strip()
        error_msg = error_output[:500] if error_output else "unknown error"
        return False, status.delta_time, f"ts compilation failed: {error_msg}"
    
    return True, status.delta_time, None


def execute_zk_compile(
    project_dir: Path,
    timeout: float | None = 300.0,
) -> tuple[bool, float | None, str | None]:
    """
    Stage 1: Compile ZkProgram (generate verification key).
    
    Args:
        project_dir: Project directory with compiled JavaScript
        timeout: Compilation timeout
    
    Returns:
        Tuple of (success, compile_time, error_message)
    """
    # Create compile runner if not exists
    compile_runner = project_dir / COMPILE_RUNNER_FILENAME
    if not compile_runner.exists():
        create_compile_runner(project_dir, "circuit")
    
    # Check if already compiled
    vk_file = project_dir / VK_FILENAME
    if vk_file.exists():
        logger.debug(f"Reusing compiled ZkProgram in {project_dir}")
        return True, 0.0, None
    
    logger.debug(f"Compiling ZkProgram in {project_dir}...")
    status = run_stage_runner(project_dir, COMPILE_RUNNER_FILENAME, timeout=timeout)
    success, result, error = parse_stage_result(status)
    
    compile_time = result.get("time_ms", 0) / 1000.0 if result else status.delta_time
    
    return success, compile_time, error


def execute_prove(
    project_dir: Path,
    inputs: dict[str, str],
    input_types: list[str],
    timeout: float | None = 300.0,
) -> tuple[bool, float | None, str | None, str | None]:
    """
    Stage 2: Generate proof with given inputs.
    
    Args:
        project_dir: Project directory with compiled ZkProgram
        inputs: Input values
        input_types: Types of inputs
        timeout: Proving timeout
    
    Returns:
        Tuple of (success, prove_time, public_output, error_message)
    """
    # Create prove runner with inputs
    create_prove_runner(project_dir, "circuit", inputs, input_types)
    
    logger.debug(f"Proving circuit in {project_dir} with inputs: {inputs}")
    status = run_stage_runner(project_dir, PROVE_RUNNER_FILENAME, timeout=timeout)
    success, result, error = parse_stage_result(status)
    
    prove_time = result.get("time_ms", 0) / 1000.0 if result else status.delta_time
    public_output = result.get("public_output") if result else None
    
    return success, prove_time, public_output, error


def execute_verify(
    project_dir: Path,
    timeout: float | None = 60.0,
) -> tuple[bool, float | None, str | None]:
    """
    Stage 3: Verify the proof.
    
    Args:
        project_dir: Project directory with proof and verification key
        timeout: Verification timeout
    
    Returns:
        Tuple of (success, verify_time, error_message)
    """
    # Create verify runner if not exists
    verify_runner = project_dir / VERIFY_RUNNER_FILENAME
    if not verify_runner.exists():
        create_verify_runner(project_dir, "circuit")
    
    logger.debug(f"Verifying proof in {project_dir}...")
    status = run_stage_runner(project_dir, VERIFY_RUNNER_FILENAME, timeout=timeout)
    success, result, error = parse_stage_result(status)
    
    verify_time = result.get("time_ms", 0) / 1000.0 if result else status.delta_time
    
    return success, verify_time, error


# ================================================================
#                     Metamorphic Testing
# ================================================================


def is_assertion_error(error: str | None) -> bool:
    """Check if an error is an assertion failure (expected for random circuits)."""
    if error is None:
        return False
    assertion_patterns = [
        "assertion failed",
        "Bool.assertTrue",
        "constraint unsatisfied",
    ]
    error_lower = error.lower()
    return any(pattern.lower() in error_lower for pattern in assertion_patterns)


def run_single_iteration(
    c1_project: Path,
    c2_project: Path,
    inputs: dict[str, str],
    input_types: list[str],
    run_prove_and_verify: bool = True,
    ts_compile_timeout: float | None = 60.0,
    zk_compile_timeout: float | None = 300.0,
    prove_timeout: float | None = 300.0,
    verify_timeout: float | None = 60.0,
) -> TestIteration:
    """
    Run a single metamorphic test iteration with separated pipeline stages.
    
    Pipeline Stages:
    1. TypeScript Compile (tsc) - compile .ts to .js
    2. ZkProgram Compile - generate verification key
    3. Prove - generate proof with inputs
    4. Verify - verify the proof (optional, controlled by run_prove_and_verify)
    
    Metamorphic testing logic:
    - If both circuits fail with assertion errors, this is NOT an error (ignored)
    - If one circuit fails and the other succeeds, this IS a metamorphic error
    - If both succeed but outputs differ, this IS a metamorphic error
    - Compilation errors are always real errors (code generation bug)
    
    Args:
        c1_project: Original circuit project directory
        c2_project: Transformed circuit project directory
        inputs: Input values
        input_types: Types of inputs
        run_prove_and_verify: Whether to run verify stage
        ts_compile_timeout: TypeScript compilation timeout
        zk_compile_timeout: ZkProgram compilation timeout  
        prove_timeout: Proving timeout
        verify_timeout: Verification timeout
    
    Returns:
        TestIteration with results for all stages
    """
    iteration = TestIteration()
    logger.debug(f"Starting iteration: c1={c1_project.name}, c2={c2_project.name}")
    logger.debug(f"Inputs: {inputs}, types: {input_types}")
    
    # ================================================================
    # Stage 0: TypeScript Compilation (for both circuits)
    # ================================================================
    
    logger.debug("Stage 0: TypeScript compilation...")
    
    # C1 TypeScript compile
    c1_ts_success, c1_ts_time, c1_ts_error = execute_ts_compile(c1_project, ts_compile_timeout)
    iteration.c1_ts_compile = c1_ts_success
    iteration.c1_ts_compile_time = c1_ts_time
    
    if not c1_ts_success:
        iteration.error = f"c1 ts compilation failed: {c1_ts_error}"
        logger.error(f"c1 TypeScript compilation failed: {c1_ts_error}")
        return iteration
    
    # C2 TypeScript compile
    c2_ts_success, c2_ts_time, c2_ts_error = execute_ts_compile(c2_project, ts_compile_timeout)
    iteration.c2_ts_compile = c2_ts_success
    iteration.c2_ts_compile_time = c2_ts_time
    
    if not c2_ts_success:
        iteration.error = f"c2 ts compilation failed: {c2_ts_error}"
        logger.error(f"c2 TypeScript compilation failed: {c2_ts_error}")
        return iteration
    
    # ================================================================
    # Stage 1: ZkProgram Compilation (for both circuits)
    # ================================================================
    
    logger.debug("Stage 1: ZkProgram compilation...")
    
    # C1 ZkProgram compile
    c1_zk_success, c1_zk_time, c1_zk_error = execute_zk_compile(c1_project, zk_compile_timeout)
    iteration.c1_zk_compile = c1_zk_success
    iteration.c1_zk_compile_time = c1_zk_time
    
    if not c1_zk_success:
        iteration.error = f"c1 zk compilation failed: {c1_zk_error}"
        logger.error(f"c1 ZkProgram compilation failed: {c1_zk_error}")
        return iteration
    
    # C2 ZkProgram compile
    c2_zk_success, c2_zk_time, c2_zk_error = execute_zk_compile(c2_project, zk_compile_timeout)
    iteration.c2_zk_compile = c2_zk_success
    iteration.c2_zk_compile_time = c2_zk_time
    
    if not c2_zk_success:
        iteration.error = f"c2 zk compilation failed: {c2_zk_error}"
        logger.error(f"c2 ZkProgram compilation failed: {c2_zk_error}")
        return iteration
    
    # ================================================================
    # Stage 2: Proving (for both circuits)
    # ================================================================
    
    logger.debug("Stage 2: Proving...")
    
    # C1 Prove
    c1_prove_success, c1_prove_time, c1_output, c1_prove_error = execute_prove(
        c1_project, inputs, input_types, prove_timeout
    )
    iteration.c1_prove = c1_prove_success
    iteration.c1_prove_time = c1_prove_time
    iteration.c1_output = c1_output
    
    # C2 Prove (always run even if c1 failed - for metamorphic comparison)
    c2_prove_success, c2_prove_time, c2_output, c2_prove_error = execute_prove(
        c2_project, inputs, input_types, prove_timeout
    )
    iteration.c2_prove = c2_prove_success
    iteration.c2_prove_time = c2_prove_time
    iteration.c2_output = c2_output
    
    # ================================================================
    # Metamorphic Comparison (after proving)
    # ================================================================
    
    c1_assertion_fail = not c1_prove_success and is_assertion_error(c1_prove_error)
    c2_assertion_fail = not c2_prove_success and is_assertion_error(c2_prove_error)
    
    # Case 1: Both failed with assertions - this is OK (ignored, not a metamorphic error)
    if c1_assertion_fail and c2_assertion_fail:
        iteration.c1_ignored_error = c1_prove_error
        iteration.c2_ignored_error = c2_prove_error
        logger.debug(f"Both circuits failed with assertions (ignored): c1={c1_prove_error}, c2={c2_prove_error}")
        return iteration
    
    # Case 2: c1 failed but c2 succeeded - metamorphic violation!
    if not c1_prove_success and c2_prove_success:
        iteration.error = MinaError.METAMORPHIC_VIOLATION_EXECUTION
        logger.warning(f"Metamorphic violation: c1 prove failed ({c1_prove_error}) but c2 succeeded")
        return iteration
    
    # Case 3: c1 succeeded but c2 failed - metamorphic violation!
    if c1_prove_success and not c2_prove_success:
        iteration.error = MinaError.METAMORPHIC_VIOLATION_EXECUTION
        logger.warning(f"Metamorphic violation: c1 prove succeeded but c2 failed ({c2_prove_error})")
        return iteration
    
    # Case 4: Both failed with non-assertion errors
    if not c1_prove_success and not c2_prove_success:
        iteration.c1_ignored_error = c1_prove_error
        iteration.c2_ignored_error = c2_prove_error
        logger.debug(f"Both circuits prove failed (ignored): c1={c1_prove_error}, c2={c2_prove_error}")
        return iteration
    
    # Case 5: Both succeeded - check outputs match
    if c1_output != c2_output:
        iteration.error = MinaError.DIVERGING_SIGNALS
        logger.warning(f"Diverging outputs: c1={c1_output}, c2={c2_output}")
        return iteration
    
    logger.debug(f"Prove stage passed: both outputs = {c1_output}")
    
    # ================================================================
    # Stage 3: Verification (optional, controlled by online tuning)
    # ================================================================
    
    if not run_prove_and_verify:
        logger.debug("Skipping verify stage (online tuning)")
        return iteration
    
    logger.debug("Stage 3: Verification...")
    
    # C1 Verify
    c1_verify_success, c1_verify_time, c1_verify_error = execute_verify(c1_project, verify_timeout)
    iteration.c1_verify = c1_verify_success
    iteration.c1_verify_time = c1_verify_time
    
    if not c1_verify_success:
        iteration.error = f"c1 verification failed: {c1_verify_error}"
        logger.error(f"c1 verification failed: {c1_verify_error}")
        return iteration
    
    # C2 Verify
    c2_verify_success, c2_verify_time, c2_verify_error = execute_verify(c2_project, verify_timeout)
    iteration.c2_verify = c2_verify_success
    iteration.c2_verify_time = c2_verify_time
    
    if not c2_verify_success:
        iteration.error = f"c2 verification failed: {c2_verify_error}"
        logger.error(f"c2 verification failed: {c2_verify_error}")
        return iteration
    
    logger.debug("Metamorphic test passed: all stages successful")
    return iteration


def run_metamorphic_tests(
    metamorphic_pair: MetamorphicCircuitPair,
    test_seed: int,
    curve: CurvePrime,
    working_dir: Path,
    config: MinaConfig,
    is_boolean_circuit: bool = False,
    online_tuning: 'OnlineTuning | None' = None,
) -> MinaResult:
    """
    Run metamorphic tests on a circuit pair with separated pipeline.
    
    Args:
        metamorphic_pair: Original and transformed circuit pair
        test_seed: Seed for test input generation
        curve: Field curve for the circuits
        working_dir: Directory for test execution
        config: Mina test configuration
        is_boolean_circuit: Whether this is a boolean circuit
        online_tuning: Optional online tuning for prove/verify stages
    
    Returns:
        MinaResult with all test iterations
    """
    result = MinaResult()
    rng = Random(test_seed)
    
    c1_circuit = metamorphic_pair.fst
    c2_circuit = metamorphic_pair.snd
    
    # Prepare projects
    c1_project, c1_code = prepare_project(
        working_dir, "c1", c1_circuit, curve, is_boolean_circuit
    )
    c2_project, c2_code = prepare_project(
        working_dir, "c2", c2_circuit, curve, is_boolean_circuit
    )
    
    result.original_code = c1_code
    result.transformed_code = c2_code
    
    # Log generated code (similar to Circom backend)
    logger.info("Original Mina/o1js Code:")
    logger.info(c1_code)
    logger.info("Transformed Mina/o1js Code:")
    logger.info(c2_code)
    
    # Determine input types
    input_types = ["Bool" if is_boolean_circuit else "Field"] * len(c1_circuit.inputs)
    
    # Run test iterations
    for i in range(config.test_iterations):
        logger.info(f"Running test iteration {i + 1}/{config.test_iterations}")
        
        # Generate random inputs
        inputs = random_input(
            c1_circuit.inputs,
            input_types,
            curve,
            config.boundary_input_probability,
            rng,
        )
        
        # Determine if we should run prove/verify based on online tuning
        run_verify = True
        if online_tuning is not None:
            online_tuning.inc_prove_and_verify_ticks()
            run_verify = online_tuning.is_prove_and_verify(rng)
            if run_verify:
                online_tuning.inc_prove_and_verify_exec()
        
        # Run iteration with separated pipeline
        iteration = run_single_iteration(
            c1_project, c2_project, inputs, input_types,
            run_prove_and_verify=run_verify,
        )
        result.iterations.append(iteration)
        
        # Update online tuning with timing info
        if online_tuning is not None:
            # Add compilation times as general execution time
            if iteration.c1_ts_compile_time:
                online_tuning.add_general_execution_time(iteration.c1_ts_compile_time)
            if iteration.c2_ts_compile_time:
                online_tuning.add_general_execution_time(iteration.c2_ts_compile_time)
            if iteration.c1_zk_compile_time:
                online_tuning.add_general_execution_time(iteration.c1_zk_compile_time)
            if iteration.c2_zk_compile_time:
                online_tuning.add_general_execution_time(iteration.c2_zk_compile_time)
            
            # Add prove/verify times
            if iteration.c1_prove_time:
                online_tuning.add_prove_or_verify_time(iteration.c1_prove_time)
            if iteration.c2_prove_time:
                online_tuning.add_prove_or_verify_time(iteration.c2_prove_time)
            if iteration.c1_verify_time:
                online_tuning.add_prove_or_verify_time(iteration.c1_verify_time)
            if iteration.c2_verify_time:
                online_tuning.add_prove_or_verify_time(iteration.c2_verify_time)
        
        # Stop on error
        if iteration.is_error():
            logger.error(f"Test iteration {i + 1} failed: {iteration.error}")
            break
    
    return result

