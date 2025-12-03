"""
All functions and classes related to using the PICUS based oracle
"""

from enum import StrEnum
from circuzz.common.field import CurvePrime
from circuzz.common.helper import generate_random_circuit
from circuzz.ir.config import IRConfig
from circuzz.ir.nodes import Circuit
import tempfile
from pathlib import Path
import subprocess  

PICUS_COMMAND = "/Picus/run-picus"  # Path to the PICUS executable

class ConstraintLevel(StrEnum):
    FULLY_CONSTRAINED = "fully_constrained"
    UNDER_CONSTRAINED = "under_constrained"
    INCONCLUSIVE = "inconclusive"

class PICUSCheckResult:
    def __init__(self, constraint_level: ConstraintLevel):
        self.constraint_level = constraint_level

def run_picus_check(circuit: Circuit) -> PICUSCheckResult:
    # Save citcuit to a temporary file
    with tempfile.TemporaryDirectory() as tmpdirname:
        circuit_path = Path(tmpdirname) / "circuit.circom"
        with open(circuit_path, 'w') as f:
            f.write(circuit.to_circom())

        # Run picus check command
        result = subprocess.run(
            [PICUS_COMMAND, str(circuit_path)],
        )

        if "The circuit is properly constrained" in result.stdout.decode():
            return PICUSCheckResult(ConstraintLevel.FULLY_CONSTRAINED)
        elif "The circuit is underconstrained" in result.stdout.decode():
            return PICUSCheckResult(ConstraintLevel.UNDER_CONSTRAINED)
        else:
            return PICUSCheckResult(ConstraintLevel.INCONCLUSIVE)

def is_properly_constrained(circuit: Circuit) -> bool:
    return run_picus_check(circuit).constraint_level == ConstraintLevel.FULLY_CONSTRAINED

def generate_picus_constrained_circuit \
    ( curve: CurvePrime
    , exclude_prime: bool
    , config: IRConfig
    , seed: int
    ) -> tuple[Circuit, int]:
    """
    Uses normal random circuit generation but ensures the circuit is
    properly constrained for use with the PICUS oracle.

    It also returns the number of tries it took to generate such a circuit.
    """

    circuit = None
    num_tries = 0
    while not circuit or not is_properly_constrained(circuit):
        circuit = generate_random_circuit(curve, exclude_prime, config, seed)
        seed += 1  # Change seed to get a different circuit next time if needed.
        num_tries += 1

    return circuit, num_tries