
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime grumpkin --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `-1.6770412921905518s`
  * returncode: `101`

### STDOUT
~~~
template instances: 8

~~~

### STDERR
~~~
thread 'main' panicked at constraint_list/src/constraint_simplification.rs:566:34:
called `Result::unwrap()` on an `Err` value: SystemTimeError(1.710698354s)
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace

~~~

