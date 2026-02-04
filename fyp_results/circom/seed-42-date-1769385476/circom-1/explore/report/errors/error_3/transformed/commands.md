
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bls12381 --O2 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `1.9794573783874512s`
  * returncode: `0`

### STDOUT
~~~
template instances: 9
non-linear constraints: 7365
linear constraints: 0
public inputs: 0
private inputs: 2 (none belong to witness)
public outputs: 2
wires: 7343
labels: 12826
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
  * time: `50.07800793647766s`
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
  * time: `0.017286062240600586s`
  * returncode: `-6`

### STDOUT
~~~
Failed assert in template/function Num2Bits line 38. Followed trace of components: main.comp_264

~~~

### STDERR
~~~
circuit: circuit.cpp:232: void Num2Bits_1_run(uint, Circom_CalcWit*): Assertion `Fr_isTrue(&expaux[0])' failed.

~~~

