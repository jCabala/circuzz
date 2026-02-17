
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime pallas --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `-0.923614501953125s`
  * returncode: `101`

### STDOUT
~~~
template instances: 9

~~~

### STDERR
~~~
thread 'main' panicked at constraint_list/src/constraint_simplification.rs:591:34:
called `Result::unwrap()` on an `Err` value: SystemTimeError(998.215178ms)
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

~~~

