
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bls12381 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.46921873092651367s`
  * returncode: `0`

### STDOUT
~~~
template instances: 12
non-linear constraints: 1783
linear constraints: 22
public inputs: 0
private inputs: 1
public outputs: 0
wires: 1800
labels: 2620
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
  * time: `0.1977672576904297s`
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
Error in template Num2Bits_6 line: 38
Error in template main_template_11 line: 51

    at /tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:166:27
    at Array.forEach (<anonymous>)
    at WitnessCalculator._doCalculateWitness (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:141:14)
    at WitnessCalculator.calculateWTNSBin (/tmp/circom-1/explore/working/transformed/circuit_js/witness_calculator.js:216:20)
    at /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js:16:38

Node.js v18.20.4

~~~

