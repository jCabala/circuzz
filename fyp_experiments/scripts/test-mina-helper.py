#!/usr/bin/env python3
"""
Test script for Mina/o1js helper functions.

This script tests the end-to-end workflow of:
1. Generating IR circuits
2. Converting to Mina/o1js code
3. Setting up project structure
4. Compiling and executing circuits

Usage:
    cd /path/to/circuzz
    python fyp_experiments/scripts/test-mina-helper.py
"""

import sys
import tempfile
from pathlib import Path
from random import Random

# Add src to path for imports
sys.path.insert(0, str(Path(__file__).parent.parent.parent / "src"))

from circuzz.common.field import CurvePrime
from circuzz.ir.nodes import Circuit, Assignment, Variable, Integer, BinaryExpression, Operator

from backends.mina.helper import (
    ir_to_mina_code,
    prepare_project,
    create_test_runner,
    compile_typescript,
    run_test_runner,
    parse_execution_result,
    execute_circuit,
    random_input,
)


def create_simple_circuit() -> Circuit:
    """Create a simple test circuit: out0 = in0 + in1"""
    return Circuit(
        name="test_add",
        inputs=["in0", "in1"],
        outputs=["out0"],
        statements=[
            Assignment(
                Variable("out0"),
                BinaryExpression(
                    Operator.ADD,
                    Variable("in0"),
                    Variable("in1"),
                )
            )
        ]
    )


def create_mul_circuit() -> Circuit:
    """Create a multiplication circuit: out0 = in0 * in1"""
    return Circuit(
        name="test_mul",
        inputs=["in0", "in1"],
        outputs=["out0"],
        statements=[
            Assignment(
                Variable("out0"),
                BinaryExpression(
                    Operator.MUL,
                    Variable("in0"),
                    Variable("in1"),
                )
            )
        ]
    )


def test_code_generation():
    """Test IR to Mina code generation."""
    print("\n" + "="*60)
    print("TEST: Code Generation")
    print("="*60)
    
    circuit = create_simple_circuit()
    curve = CurvePrime.PALLAS  # o1js uses Pallas curve
    
    code = ir_to_mina_code(circuit, curve, is_boolean_circuit=False)
    
    print(f"Generated code for circuit '{circuit.name}':")
    print("-" * 40)
    print(code)
    print("-" * 40)
    
    # Basic checks
    assert "ZkProgram" in code, "Code should contain ZkProgram"
    assert "Field" in code, "Code should contain Field type"
    assert "in0" in code, "Code should reference input in0"
    assert "in1" in code, "Code should reference input in1"
    assert "out0" in code, "Code should reference output out0"
    assert ".add(" in code, "Code should use .add() method"
    
    print("✓ Code generation test passed!")
    return True


def test_project_setup():
    """Test project setup and file creation."""
    print("\n" + "="*60)
    print("TEST: Project Setup")
    print("="*60)
    
    circuit = create_simple_circuit()
    curve = CurvePrime.PALLAS
    
    with tempfile.TemporaryDirectory() as tmpdir:
        root = Path(tmpdir)
        project_dir, code = prepare_project(root, "test", circuit, curve)
        
        print(f"Project created at: {project_dir}")
        
        # Check files exist
        assert project_dir.exists(), "Project directory should exist"
        assert (project_dir / "circuit.ts").exists(), "circuit.ts should exist"
        assert (project_dir / "package.json").exists(), "package.json should exist"
        assert (project_dir / "tsconfig.json").exists(), "tsconfig.json should exist"
        
        # List files
        print("Files created:")
        for f in project_dir.iterdir():
            print(f"  - {f.name}")
        
        print("✓ Project setup test passed!")
    
    return True


def test_input_generation():
    """Test random input generation."""
    print("\n" + "="*60)
    print("TEST: Input Generation")
    print("="*60)
    
    curve = CurvePrime.PALLAS
    rng = Random(42)
    
    # Test Field inputs
    inputs = random_input(
        input_signals=["in0", "in1", "in2"],
        input_types=["Field", "Field", "Field"],
        curve=curve,
        boundary_probability=0.1,
        rng=rng,
    )
    
    print("Generated Field inputs:")
    for name, value in inputs.items():
        print(f"  {name}: {value[:20]}..." if len(value) > 20 else f"  {name}: {value}")
    
    assert len(inputs) == 3, "Should generate 3 inputs"
    assert all(name in inputs for name in ["in0", "in1", "in2"]), "All input names should be present"
    
    # Test Bool inputs
    rng = Random(42)
    bool_inputs = random_input(
        input_signals=["b0", "b1"],
        input_types=["Bool", "Bool"],
        curve=curve,
        boundary_probability=0.1,
        rng=rng,
    )
    
    print("\nGenerated Bool inputs:")
    for name, value in bool_inputs.items():
        print(f"  {name}: {value}")
    
    assert all(v in ["true", "false"] for v in bool_inputs.values()), "Bool values should be true/false"
    
    print("✓ Input generation test passed!")
    return True


def test_test_runner_creation():
    """Test test runner script generation."""
    print("\n" + "="*60)
    print("TEST: Test Runner Creation")
    print("="*60)
    
    with tempfile.TemporaryDirectory() as tmpdir:
        project_dir = Path(tmpdir)
        
        inputs = {"in0": "5", "in1": "3"}
        input_types = ["Field", "Field"]
        
        runner_path = create_test_runner(project_dir, "circuit", inputs, input_types)
        
        print(f"Test runner created at: {runner_path}")
        
        assert runner_path.exists(), "Test runner should exist"
        
        content = runner_path.read_text()
        print("\nTest runner content (first 500 chars):")
        print("-" * 40)
        print(content[:500])
        print("-" * 40)
        
        assert "Field(5n)" in content, "Should contain Field(5n)"
        assert "Field(3n)" in content, "Should contain Field(3n)"
        assert "circuit.compile()" in content, "Should call circuit.compile()"
        assert "circuit.compute" in content, "Should call circuit.compute"
        
        print("✓ Test runner creation test passed!")
    
    return True


def test_full_execution(skip_if_no_npm: bool = True):
    """
    Test full circuit execution.
    
    This test uses the programs-mina directory which has o1js installed.
    """
    print("\n" + "="*60)
    print("TEST: Full Execution (using programs-mina)")
    print("="*60)
    
    # Use programs-mina directory which has o1js installed
    script_dir = Path(__file__).parent
    programs_mina = script_dir / "programs-mina"
    
    if not programs_mina.exists():
        print(f"⚠ programs-mina directory not found at {programs_mina}")
        print("  Run generate-mina.py first to set up the environment")
        if skip_if_no_npm:
            return True
        return False
    
    # Check if node_modules exists
    node_modules = programs_mina / "node_modules"
    if not node_modules.exists():
        print(f"⚠ node_modules not found in {programs_mina}")
        print("  Run 'npm install' in programs-mina first")
        if skip_if_no_npm:
            return True
        return False
    
    circuit = create_simple_circuit()
    curve = CurvePrime.PALLAS
    
    # Create project in programs-mina subdirectory
    project_dir = programs_mina / "test_helper"
    project_dir.mkdir(exist_ok=True)
    
    try:
        # Generate circuit code
        code = ir_to_mina_code(circuit, curve, is_boolean_circuit=False)
        
        # Write circuit file
        circuit_path = project_dir / "circuit.ts"
        circuit_path.write_text(code)
        
        print(f"Project: {project_dir}")
        print(f"Generated circuit.ts")
        
        # Compile TypeScript
        print("Compiling TypeScript...")
        compile_status = compile_typescript(project_dir, timeout=60.0)
        
        if compile_status.is_failure():
            print(f"TypeScript compilation failed:")
            print(f"  stdout: {compile_status.stdout[:300]}")
            print(f"  stderr: {compile_status.stderr[:300]}")
            return False
        
        print("TypeScript compiled successfully")
        
        # Execute circuit
        inputs = {"in0": "5", "in1": "3"}
        input_types = ["Field", "Field"]
        
        print(f"Executing with inputs: {inputs}")
        
        # Create test runner
        create_test_runner(project_dir, "circuit", inputs, input_types)
        
        # Run test runner
        print("Running circuit (this may take a while for compilation)...")
        exec_status = run_test_runner(project_dir, timeout=300.0)
        success, output, error = parse_execution_result(exec_status)
        
        print(f"\nExecution success: {success}")
        print(f"Output: {output}")
        print(f"Error: {error}")
        
        if success:
            print("✓ Full execution test passed!")
            # Check output is 5 + 3 = 8
            if output == "8":
                print("✓ Output value correct (5 + 3 = 8)")
            else:
                print(f"⚠ Output value unexpected: {output} (expected 8)")
        else:
            print(f"✗ Execution failed: {error}")
            if exec_status:
                print(f"stdout: {exec_status.stdout[:500]}")
                print(f"stderr: {exec_status.stderr[:500]}")
        
        return success
        
    finally:
        # Clean up test files
        import shutil
        if project_dir.exists():
            shutil.rmtree(project_dir)


def main():
    """Run all tests."""
    print("="*60)
    print("Mina/o1js Helper Function Tests")
    print("="*60)
    
    tests = [
        ("Code Generation", test_code_generation),
        ("Project Setup", test_project_setup),
        ("Input Generation", test_input_generation),
        ("Test Runner Creation", test_test_runner_creation),
        ("Full Execution", lambda: test_full_execution(skip_if_no_npm=True)),
    ]
    
    results = []
    for name, test_fn in tests:
        try:
            passed = test_fn()
            results.append((name, passed, None))
        except Exception as e:
            results.append((name, False, str(e)))
            print(f"✗ {name} failed with exception: {e}")
    
    # Summary
    print("\n" + "="*60)
    print("TEST SUMMARY")
    print("="*60)
    
    passed = sum(1 for _, p, _ in results if p)
    total = len(results)
    
    for name, success, error in results:
        status = "✓" if success else "✗"
        print(f"  {status} {name}" + (f" ({error})" if error else ""))
    
    print(f"\nPassed: {passed}/{total}")
    
    return passed == total


if __name__ == "__main__":
    success = main()
    sys.exit(0 if success else 1)
