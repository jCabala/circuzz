
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime bn128 --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.05930614471435547s`
  * returncode: `0`

### STDOUT
~~~
template instances: 3
non-linear constraints: 2
linear constraints: 4
public inputs: 0
private inputs: 2
public outputs: 0
wires: 8
labels: 8
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
  * time: `7.224997520446777s`
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
  * time: `0.003645658493041992s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs plonk setup /tmp/circom-1/explore/working/origin/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/origin/plonk_final.zkey`
  * time: `1.4561266899108887s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: Reading r1cs
[INFO]  snarkJS: Plonk constraints: 6
Variable not used
Variable not used
[INFO]  snarkJS: Setup Finished

~~~

### STDERR
~~~

~~~


# snarkjs-prove

  * command: `/usr/local/bin/snarkjs plonk prove /tmp/circom-1/explore/working/origin/plonk_final.zkey /tmp/circom-1/explore/working/origin/witness.cpp.wtns /tmp/circom-1/explore/working/origin/proof.json /tmp/circom-1/explore/working/origin/public.json`
  * time: `1.1632609367370605s`
  * returncode: `1`

### STDOUT
~~~
[ERROR] snarkJS: Error: Evaluations.getEvaluation() out of bounds
    at Evaluations.getEvaluation (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:8122:19)
    at computeT (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:8727:50)
    at async round3 (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:8585:9)
    at async plonk16Prove (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:8260:5)
    at async Object.plonkProve [as action] (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:13627:36)
    at async clProcessor (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:517:27)

~~~

### STDERR
~~~

~~~

