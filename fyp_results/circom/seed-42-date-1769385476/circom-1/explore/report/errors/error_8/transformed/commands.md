
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `0.608543872833252s`
  * returncode: `0`

### STDOUT
~~~
template instances: 11
non-linear constraints: 1778
linear constraints: 0
public inputs: 0
private inputs: 2
public outputs: 1
wires: 1775
labels: 4148
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


# circom-witness-preparation-cpp

  * command: `/usr/bin/make -C /tmp/circom-1/explore/working/transformed/circuit_cpp`
  * time: `44.17405152320862s`
  * returncode: `0`

### STDOUT
~~~
make: Entering directory '/tmp/circom-1/explore/working/transformed/circuit_cpp'
g++ -c calcwit.cpp -std=c++11 -O3 -I.
g++ -c circuit.cpp -std=c++11 -O3 -I.
g++ -c main.cpp -std=c++11 -O3 -I.
g++ -o circuit calcwit.o circuit.o main.o -lgmp 
make: Leaving directory '/tmp/circom-1/explore/working/transformed/circuit_cpp'

~~~

### STDERR
~~~

~~~


# circom-witness-cpp

  * command: `/tmp/circom-1/explore/working/transformed/circuit_cpp/circuit /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.cpp.wtns`
  * time: `0.018111228942871094s`
  * returncode: `-6`

### STDOUT
~~~
Failed assert in template/function main_template line 3140. Followed trace of components: main

~~~

### STDERR
~~~
circuit: circuit.cpp:20246: void main_template_10_run(uint, Circom_CalcWit*): Assertion `Fr_isTrue(Fr_eq(ctx->signalValues[ctx->componentMemory[mySubcomponents[25]].signalStart + 0],1ull))' failed.

~~~

