
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.1915733814239502s`
  * returncode: `101`

### STDOUT
~~~
template instances: 11

~~~

### STDERR
~~~
thread 'main' panicked at constraint_list/src/constraint_simplification.rs:539:34:
called `Result::unwrap()` on an `Err` value: SystemTimeError(2.863810542s)
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

~~~

