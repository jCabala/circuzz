
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime secq256r1 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.9487607479095459s`
  * returncode: `0`

### STDOUT
~~~
template instances: 10
non-linear constraints: 3816
linear constraints: 29
public inputs: 0
private inputs: 0
public outputs: 0
wires: 3833
labels: 6186
Written successfully: /tmp/circom-1/explore/working/transformed/circuit.r1cs
Written successfully: /tmp/circom-1/explore/working/transformed/circuit.sym
Constraints written in: /tmp/circom-1/explore/working/transformed/circuit_constraints.json
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_cpp/circuit.cpp and /tmp/circom-1/explore/working/transformed/circuit_cpp/circuit.dat
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_cpp/main.cpp, circom.hpp, calcwit.hpp, calcwit.cpp, fr.hpp, fr.cpp, fr.asm and Makefile
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm
Everything went okay

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.js.wtns`
  * time: `0.1720130443572998s`
  * returncode: `1`

### STDOUT
~~~

~~~

### STDERR
~~~
/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:38
                throw new Error(err + errStr);
                      ^

Error: Assert Failed.
Error in template Num2Bits_0 line: 38
Error in template main_template_9 line: 1306

    at exceptionHandler (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:38:23)
    at init (wasm://wasm/0018fa0e:wasm-function[93]:0x5fe4)
    at WitnessCalculator._doCalculateWitness (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:133:31)
    at WitnessCalculator.calculateWTNSBin (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:216:20)
    at /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js:16:38

Node.js v18.20.4

~~~

