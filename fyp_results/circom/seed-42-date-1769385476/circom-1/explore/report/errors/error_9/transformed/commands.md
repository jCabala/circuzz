
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `1.2392537593841553s`
  * returncode: `0`

### STDOUT
~~~
template instances: 13
non-linear constraints: 4843
linear constraints: 3200
public inputs: 0
private inputs: 0
public outputs: 1
wires: 8031
labels: 8031
Written successfully: /tmp/circom-1/explore/working/transformed/circuit.r1cs
Written successfully: /tmp/circom-1/explore/working/transformed/circuit.sym
Constraints written in: /tmp/circom-1/explore/working/transformed/circuit_constraints.json
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_cpp/circuit.cpp and /tmp/circom-1/explore/working/transformed/circuit_cpp/circuit.dat
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_cpp/main.cpp, circom.hpp, calcwit.hpp, calcwit.cpp, fr.hpp, Makefile and json2bin64.cpp
Written successfully: /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm
Everything went okay

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.js.wtns`
  * time: `0.36876416206359863s`
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
Error in template main_template_12 line: 61

    at exceptionHandler (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:38:23)
    at init (wasm://wasm/001d124a:wasm-function[93]:0x2868)
    at WitnessCalculator._doCalculateWitness (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:133:31)
    at WitnessCalculator.calculateWTNSBin (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:216:20)
    at /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js:16:38

Node.js v18.20.4

~~~

