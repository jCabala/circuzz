"""
Mina/o1js command execution utilities.

This module handles running o1js compiler and test commands.
"""

from pathlib import Path
import shutil

from circuzz.common.command import ExecStatus, execute_command


def get_node_path() -> str:
    """Get the path to node executable."""
    node = shutil.which("node")
    assert node, "Unable to find 'node' in PATH!"
    return node


def get_npm_path() -> str:
    """Get the path to npm executable."""
    npm = shutil.which("npm")
    assert npm, "Unable to find 'npm' in PATH!"
    return npm


def get_npx_path() -> str:
    """Get the path to npx executable."""
    npx = shutil.which("npx")
    assert npx, "Unable to find 'npx' in PATH!"
    return npx


def node_version() -> ExecStatus:
    """Get the installed Node.js version."""
    command = [get_node_path(), "--version"]
    return execute_command(command, "node-version")


def npm_version() -> ExecStatus:
    """Get the installed npm version."""
    command = [get_npm_path(), "--version"]
    return execute_command(command, "npm-version")


def npm_install(working_dir: Path, timeout: float | None = None) -> ExecStatus:
    """
    Run npm install in the given directory.
    
    Args:
        working_dir: Directory containing package.json
        timeout: Optional timeout in seconds
    
    Returns:
        ExecStatus containing command output and status
    """
    command = [get_npm_path(), "install", "--silent"]
    return execute_command(command, "npm-install", working_dir, timeout)


def tsc_compile(working_dir: Path, timeout: float | None = None) -> ExecStatus:
    """
    Run TypeScript compiler in the given directory.
    
    Args:
        working_dir: Directory containing tsconfig.json and TypeScript files
        timeout: Optional timeout in seconds
    
    Returns:
        ExecStatus containing command output and status
    """
    command = [get_npx_path(), "tsc"]
    return execute_command(command, "tsc-compile", working_dir, timeout)


def run_test_runner(
    working_dir: Path, 
    runner_file: str = "test-runner.mjs",
    timeout: float | None = None,
) -> ExecStatus:
    """
    Run the o1js test runner script.
    
    Args:
        working_dir: Directory containing the test runner
        runner_file: Name of the test runner file
        timeout: Optional timeout in seconds
    
    Returns:
        ExecStatus containing command output and status
    """
    command = [
        get_node_path(),
        "--experimental-vm-modules",
        runner_file,
    ]
    return execute_command(command, "mina-execute", working_dir, timeout)


def run_o1js_build_and_test(
    working_dir: Path,
    runner_file: str = "test-runner.mjs",
    compile_timeout: float | None = 60.0,
    run_timeout: float | None = 120.0,
) -> tuple[ExecStatus, ExecStatus | None]:
    """
    Build and run an o1js project.
    
    This function:
    1. Compiles TypeScript to JavaScript
    2. Runs the test runner
    
    Args:
        working_dir: Directory containing the o1js project
        runner_file: Name of the test runner file
        compile_timeout: Timeout for TypeScript compilation
        run_timeout: Timeout for test execution
    
    Returns:
        Tuple of (tsc_status, run_status or None if compile failed)
    """
    # Step 1: Compile TypeScript
    tsc_status = tsc_compile(working_dir, timeout=compile_timeout)
    
    if tsc_status.return_code != 0:
        return (tsc_status, None)
    
    # Step 2: Run test runner
    run_status = run_test_runner(working_dir, runner_file, timeout=run_timeout)
    
    return (tsc_status, run_status)
