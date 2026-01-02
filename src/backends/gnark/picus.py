"""
All functions and classes related to using the PICUS based oracle for Gnark
"""

from enum import StrEnum
from circuzz.common.colorlogs import get_color_logger
from circuzz.common.field import CurvePrime
from circuzz.common.helper import generate_random_circuit
from circuzz.ir.config import IRConfig
from circuzz.ir.nodes import Circuit
from .ir2gnark import IR2GnarkVisitor
from .emitter import EmitVisitor
from random import Random
import tempfile
from pathlib import Path
import subprocess  

logger = get_color_logger()

PICUS_COMMAND = "/Picus/run-picus"  # Path to the PICUS executable

class ConstraintLevel(StrEnum):
    FULLY_CONSTRAINED = "fully_constrained"
    UNDER_CONSTRAINED = "under_constrained"
    INCONCLUSIVE = "inconclusive"

class PICUSCheckResult:
    def __init__(self, constraint_level: ConstraintLevel):
        self.constraint_level = constraint_level

def ir_to_gnark_ast(
    circuit: Circuit,
) -> object:
    """Convert an IR `Circuit` to Gnark AST (Document)."""
    visitor = IR2GnarkVisitor()
    return visitor.transform(circuit)

def ir_to_gnark_code(
    circuit: Circuit,
) -> str:
    """Convert an IR `Circuit` to Gnark source code string."""
    gnark_ast = ir_to_gnark_ast(circuit)
    emitter = EmitVisitor(add_picus_annotations=True)
    return emitter.emit(gnark_ast)

def run_picus_check(gnark_code: str) -> PICUSCheckResult:
    """Run PICUS constraint checker on Gnark code."""
    logger.info("Running PICUS constraint check...")
    
    with tempfile.TemporaryDirectory() as tmpdirname:
        tmpdir = Path(tmpdirname)
        
        # Write the annotated gnark code (already has picus annotations) to a file
        main_file = tmpdir / "main.go"
        main_file.write_text(gnark_code)
        
        # Create go.mod file for module resolution
        go_mod_file = tmpdir / "go.mod"
        go_mod_content = """module circuzz_picus_check

go 1.21

require (
	github.com/Veridise/picus_gnark v0.0.0-20240313214338-a11150446abf
	github.com/consensys/gnark v0.9.1
	github.com/consensys/gnark-crypto v0.12.1
)
"""
        go_mod_file.write_text(go_mod_content)
        
        # Run go mod tidy to generate proper go.sum with all transitive dependencies
        tidy_result = subprocess.run(
            ["go", "mod", "tidy"],
            cwd=str(tmpdir),
            capture_output=True,
            text=True
        )
        
        if tidy_result.returncode != 0:
            logger.warning(f"go mod tidy failed: {tidy_result.stderr}")
            logger.debug(f"go mod tidy stdout: {tidy_result.stdout}")
            return PICUSCheckResult(ConstraintLevel.INCONCLUSIVE)
        
        # Compile the gnark circuit to sr1cs
        compile_result = subprocess.run(
            ["go", "run", "main.go"],
            cwd=str(tmpdir),
            capture_output=True,
            text=True
        )
        
        if compile_result.returncode != 0:
            logger.warning(f"Gnark compilation failed: {compile_result.stderr}")
            logger.debug(f"Gnark compilation stdout: {compile_result.stdout}")
            return PICUSCheckResult(ConstraintLevel.INCONCLUSIVE)
        
        # Check if circuit.sr1cs was generated
        sr1cs_file = tmpdir / "circuit.sr1cs"
        if not sr1cs_file.exists():
            logger.warning("Failed to generate circuit.sr1cs")
            return PICUSCheckResult(ConstraintLevel.INCONCLUSIVE)
        
        # Run picus check on the sr1cs file
        picus_result = subprocess.run(
            [PICUS_COMMAND, str(sr1cs_file)],
            capture_output=True,
            text=True
        )
        
        stdout = picus_result.stdout
        logger.debug(f"PICUS stdout: {stdout if stdout else 'No stdout'}")
        logger.debug(f"PICUS stderr: {picus_result.stderr if picus_result.stderr else 'No stderr'}")
        
        if "The circuit is properly constrained" in stdout:
            logger.info("PICUS result: Fully constrained")
            return PICUSCheckResult(ConstraintLevel.FULLY_CONSTRAINED)
        elif "The circuit is underconstrained" in stdout:
            logger.info("PICUS result: Under constrained")
            return PICUSCheckResult(ConstraintLevel.UNDER_CONSTRAINED)
        else:
            logger.info("PICUS result: Inconclusive")
            return PICUSCheckResult(ConstraintLevel.INCONCLUSIVE)

def is_properly_constrained(gnark_code: str) -> bool:
    """Check if Gnark code is properly constrained."""
    return run_picus_check(gnark_code).constraint_level == ConstraintLevel.FULLY_CONSTRAINED

def generate_picus_constrained_gnark_code \
    ( curve: CurvePrime
    , exclude_prime: bool
    , config: IRConfig
    , seed: int
    ) -> tuple[Circuit, str, int]:
    """
    Uses normal random circuit generation but ensures the circuit is
    properly constrained for use with the PICUS oracle.

    It also returns the number of tries it took to generate such a circuit.
    """
    gnark_code = None
    circuit = None
    num_tries = 0
    while not circuit or is_properly_constrained(gnark_code):
        circuit = generate_random_circuit(curve, exclude_prime, config, seed)
        gnark_code = ir_to_gnark_code(circuit)
        seed += 1  # Change seed to get a different circuit next time if needed.
        num_tries += 1

    return circuit, gnark_code, num_tries
