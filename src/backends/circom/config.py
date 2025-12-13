from dataclasses import dataclass
from enum import StrEnum
from pathlib import Path

class OracleType(StrEnum):
    CIRCUZZ = "circuzz"
    PICUS = "picus"

    @classmethod
    def from_str(cls, value: str) -> 'OracleType':
        match value:
            case "circuzz":
                return OracleType.CIRCUZZ # Default circuzz oracle
            case "picus":
                return OracleType.PICUS # PICUS based oracle for detecting under-constrained circuits
            case _:
                raise NotImplementedError(f"unimplemented oracle type '{value}', try {list(OracleType)}")

@dataclass(frozen=True)
class CircomConfig():
    """
    circom tool configuration
    """
    # probability for boundary values
    boundary_input_probability : float

    # this value determines how often tests are executed
    test_iterations  : int

    # likelihood of the CPP witness generation (if once compiled its always used for all inputs)
    likelihood_cpp_witness_generation : float

    # likelihood of the SnarkJS witness check
    likelihood_snark_witness_check : float

    # probability to constraint an assignment "<==" instead of "<--"
    constraint_assignment_probability: float

    # Oracle type
    oracle_type : OracleType = OracleType.CIRCUZZ


    @classmethod
    def from_dict(cls, value: dict[str, str]) -> 'CircomConfig':

        boundary_input_probability = float(value.get("boundary_input_probability", 0.1))
        test_iterations  = int(value.get("test_iterations", 20))
        likelihood_cpp_witness_generation = float(value.get("likelihood_cpp_witness_generation", 0.1))
        likelihood_snark_witness_check = float(value.get("likelihood_snark_witness_check", 0))
        constraint_assignment_probability = float(value.get("constraint_assignment_probability", 0.5))
        oracle_type = OracleType.from_str(value.get("oracle_type", "circuzz"))

        return CircomConfig \
            ( boundary_input_probability = boundary_input_probability
            , test_iterations = test_iterations
            , likelihood_cpp_witness_generation = likelihood_cpp_witness_generation
            , likelihood_snark_witness_check = likelihood_snark_witness_check
            , constraint_assignment_probability = constraint_assignment_probability
            , oracle_type = oracle_type
            )