
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime bls12381 --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.1708528995513916s`
  * returncode: `0`

### STDOUT
~~~
template instances: 10
non-linear constraints: 511
linear constraints: 42
public inputs: 0
private inputs: 0
public outputs: 0
wires: 551
labels: 551
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


# circom-witness-preparation-cpp

  * command: `/usr/bin/make -C /tmp/circom-1/explore/working/origin/circuit_cpp`
  * time: `9.419697761535645s`
  * returncode: `0`

### STDOUT
~~~
make: Entering directory '/tmp/circom-1/explore/working/origin/circuit_cpp'
g++ -c main.cpp -std=c++11 -O3 -I.
g++ -c calcwit.cpp -std=c++11 -O3 -I.
g++ -c fr.cpp -std=c++11 -O3 -I.
nasm -felf64 fr.asm -o fr_asm.o
g++ -c circuit.cpp -std=c++11 -O3 -I.
g++ -o circuit *.o -lgmp 
make: Leaving directory '/tmp/circom-1/explore/working/origin/circuit_cpp'

~~~

### STDERR
~~~
/usr/bin/ld: warning: fr_asm.o: missing .note.GNU-stack section implies executable stack
/usr/bin/ld: NOTE: This behaviour is deprecated and will be removed in a future version of the linker

~~~


# circom-witness-cpp

  * command: `/tmp/circom-1/explore/working/origin/circuit_cpp/circuit /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.cpp.wtns`
  * time: `0.0045778751373291016s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/origin/circuit_js/generate_witness.js /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.js.wtns`
  * time: `0.189924955368042s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~

