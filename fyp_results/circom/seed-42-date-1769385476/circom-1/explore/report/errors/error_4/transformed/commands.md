
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bls12381 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.41042208671569824s`
  * returncode: `0`

### STDOUT
~~~
template instances: 13
non-linear constraints: 1788
linear constraints: 24
public inputs: 0
private inputs: 1
public outputs: 1
wires: 1808
labels: 2656
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
  * time: `0.2009739875793457s`
  * returncode: `1`

### STDOUT
~~~

~~~

### STDERR
~~~
/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:166
                    throw new Error(err);
                          ^

Error: Error: Assert Failed.
Error in template Num2Bits_7 line: 38
Error in template main_template_12 line: 55

    at /tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:166:27
    at Array.forEach (<anonymous>)
    at WitnessCalculator._doCalculateWitness (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:141:14)
    at WitnessCalculator.calculateWTNSBin (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:216:20)
    at /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js:16:38

Node.js v18.20.4

~~~

