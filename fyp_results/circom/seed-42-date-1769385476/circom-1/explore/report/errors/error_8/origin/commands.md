
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime goldilocks --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.6944892406463623s`
  * returncode: `0`

### STDOUT
~~~
template instances: 12
non-linear constraints: 1778
linear constraints: 0
public inputs: 0
private inputs: 2
public outputs: 1
wires: 1775
labels: 4140
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


# circom-witness-preparation-cpp

  * command: `/usr/bin/make -C /tmp/circom-1/explore/working/origin/circuit_cpp`
  * time: `42.91889834403992s`
  * returncode: `0`

### STDOUT
~~~
make: Entering directory '/tmp/circom-1/explore/working/origin/circuit_cpp'
g++ -c calcwit.cpp -std=c++11 -O3 -I.
g++ -c circuit.cpp -std=c++11 -O3 -I.
g++ -c main.cpp -std=c++11 -O3 -I.
g++ -o circuit calcwit.o circuit.o main.o -lgmp 
make: Leaving directory '/tmp/circom-1/explore/working/origin/circuit_cpp'

~~~

### STDERR
~~~

~~~


# circom-witness-cpp

  * command: `/tmp/circom-1/explore/working/origin/circuit_cpp/circuit /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.cpp.wtns`
  * time: `0.004986763000488281s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  9926856927362602942

~~~

### STDERR
~~~

~~~

