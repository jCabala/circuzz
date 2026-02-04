
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime goldilocks --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `1.5587282180786133s`
  * returncode: `0`

### STDOUT
~~~
template instances: 14
non-linear constraints: 9662
linear constraints: 70
public inputs: 0
private inputs: 1 (none belong to witness)
public outputs: 2
wires: 9702
labels: 15164
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
  * time: `273.61766815185547s`
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
  * time: `0.01943206787109375s`
  * returncode: `-6`

### STDOUT
~~~
Failed assert in template/function main_template line 9130. Followed trace of components: main

~~~

### STDERR
~~~
circuit: circuit.cpp:71656: void main_template_13_run(uint, Circom_CalcWit*): Assertion `Fr_isTrue(Fr_eq(ctx->signalValues[ctx->componentMemory[mySubcomponents[68]].signalStart + 0],1ull))' failed.

~~~

