
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime goldilocks --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.10120630264282227s`
  * returncode: `0`

### STDOUT
~~~
template instances: 7
non-linear constraints: 511
linear constraints: 0
public inputs: 0
private inputs: 0
public outputs: 2
wires: 513
labels: 578
Written successfully: /tmp/circom-1/explore/working/origin/circuit.r1cs
Written successfully: /tmp/circom-1/explore/working/origin/circuit.sym
Constraints written in: /tmp/circom-1/explore/working/origin/circuit_constraints.json
Written successfully: /tmp/circom-1/explore/working/origin/circuit_cpp/circuit.cpp and /tmp/circom-1/explore/working/origin/circuit_cpp/circuit.dat
Written successfully: /tmp/circom-1/explore/working/origin/circuit_cpp/main.cpp, circom.hpp, calcwit.hpp, calcwit.cpp, fr.hpp, Makefile and json2bin64.cpp
Written successfully: /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm
Everything went okay

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/origin/circuit_js/generate_witness.js /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.js.wtns`
  * time: `0.15920639038085938s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  0
<@> out1 =  1159134157629555873

~~~

### STDERR
~~~

~~~

