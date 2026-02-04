
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bls12381 --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `2.548736810684204s`
  * returncode: `0`

### STDOUT
~~~
template instances: 14
non-linear constraints: 11191
linear constraints: 6324
public inputs: 0
private inputs: 0
public outputs: 0
wires: 17479
labels: 17479
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


# circom-witness-preparation-cpp

  * command: `/usr/bin/make -C /tmp/circom-1/explore/working/transformed/circuit_cpp`
  * time: `81.70584154129028s`
  * returncode: `0`

### STDOUT
~~~
make: Entering directory '/tmp/circom-1/explore/working/transformed/circuit_cpp'
g++ -c main.cpp -std=c++11 -O3 -I.
g++ -c calcwit.cpp -std=c++11 -O3 -I.
g++ -c fr.cpp -std=c++11 -O3 -I.
nasm -felf64 fr.asm -o fr_asm.o
g++ -c circuit.cpp -std=c++11 -O3 -I.
g++ -o circuit *.o -lgmp 
make: Leaving directory '/tmp/circom-1/explore/working/transformed/circuit_cpp'

~~~

### STDERR
~~~
/usr/bin/ld: warning: fr_asm.o: missing .note.GNU-stack section implies executable stack
/usr/bin/ld: NOTE: This behaviour is deprecated and will be removed in a future version of the linker

~~~


# circom-witness-cpp

  * command: `/tmp/circom-1/explore/working/transformed/circuit_cpp/circuit /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.cpp.wtns`
  * time: `0.05829906463623047s`
  * returncode: `-6`

### STDOUT
~~~
Failed assert in template/function Num2Bits line 38. Followed trace of components: main.comp_1

~~~

### STDERR
~~~
circuit: circuit.cpp:210: void Num2Bits_0_run(uint, Circom_CalcWit*): Assertion `Fr_isTrue(&expaux[0])' failed.

~~~

