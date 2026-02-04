
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.08312654495239258s`
  * returncode: `0`

### STDOUT
~~~
template instances: 11
non-linear constraints: 521
linear constraints: 60
public inputs: 0
private inputs: 0
public outputs: 1
wires: 586
labels: 586
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
  * time: `0.18990397453308105s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  10544893023033201266

~~~

### STDERR
~~~

~~~

