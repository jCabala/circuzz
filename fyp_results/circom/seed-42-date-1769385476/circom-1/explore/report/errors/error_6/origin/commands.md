
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime vesta --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.5903410911560059s`
  * returncode: `0`

### STDOUT
~~~
template instances: 10
non-linear constraints: 2035
linear constraints: 1569
public inputs: 0
private inputs: 0
public outputs: 0
wires: 3597
labels: 3597
Written successfully: /tmp/circom-1/explore/working/origin/circuit.r1cs
Written successfully: /tmp/circom-1/explore/working/origin/circuit.sym
Constraints written in: /tmp/circom-1/explore/working/origin/circuit_constraints.json
Written successfully: /tmp/circom-1/explore/working/origin/circuit_cpp/circuit.cpp and /tmp/circom-1/explore/working/origin/circuit_cpp/circuit.dat
Written successfully: /tmp/circom-1/explore/working/origin/circuit_cpp/main.cpp, circom.hpp, calcwit.hpp, calcwit.cpp, fr.hpp, fr.cpp, fr.asm and Makefile
Written successfully: /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm
Everything went okay

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/origin/circuit_js/generate_witness.js /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.js.wtns`
  * time: `0.2115492820739746s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~

