
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.09436655044555664s`
  * returncode: `0`

### STDOUT
~~~
template instances: 8
non-linear constraints: 512
linear constraints: 16
public inputs: 0
private inputs: 1 (none belong to witness)
public outputs: 2
wires: 531
labels: 579
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
  * time: `0.22550106048583984s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  3264928029459608667
<@> out1 =  8803907642511083809

~~~

### STDERR
~~~

~~~

