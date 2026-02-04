
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime secq256r1 --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `-2.0211896896362305s`
  * returncode: `101`

### STDOUT
~~~
template instances: 14

~~~

### STDERR
~~~
thread 'main' panicked at constraint_list/src/constraint_simplification.rs:591:34:
called `Result::unwrap()` on an `Err` value: SystemTimeError(2.851963216s)
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

~~~

