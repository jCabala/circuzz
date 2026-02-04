
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bn128 --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `4.31102991104126s`
  * returncode: `0`

### STDOUT
~~~
template instances: 13
non-linear constraints: 22149
linear constraints: 13382
public inputs: 0
private inputs: 2
public outputs: 1
wires: 35463
labels: 35463
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
  * time: `321.23904180526733s`
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
  * time: `0.015693187713623047s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  21888242871839275222246405745257275088548364400416034343698204186575808495616

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.js.wtns`
  * time: `0.3485410213470459s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  21888242871839275222246405745257275088548364400416034343698204186575808495616

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs groth16 setup /tmp/circom-1/explore/working/transformed/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/transformed/groth16_final.zkey`
  * time: `13.670943975448608s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: Reading r1cs
[INFO]  snarkJS: Reading tauG1
[INFO]  snarkJS: Reading tauG2
[INFO]  snarkJS: Reading alphatauG1
[INFO]  snarkJS: Reading betatauG1
[INFO]  snarkJS: Circuit hash: 
		221b106b 53e5d9f9 7eb46b22 3bbc143a
		3bd1419a fa130d01 2598565c 4f30e380
		0b615420 ada81c40 b00f8e22 a3c75e1e
		851a838a c7c2fc02 6e13e631 b138f8ca

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs fflonk setup /tmp/circom-1/explore/working/transformed/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/transformed/fflonk_final.zkey`
  * time: `2.4338901042938232s`
  * returncode: `1`

### STDOUT
~~~
[INFO]  snarkJS: FFLONK SETUP STARTED
[INFO]  snarkJS: > Reading PTau file
[INFO]  snarkJS: > Getting curve from PTau settings
[INFO]  snarkJS: > Reading r1cs file
[INFO]  snarkJS: > Processing FFlonk constraints
[ERROR] snarkJS: Error: Powers of Tau is not big enough for this circuit size. Section 2 too small.
    at fflonkSetup$1 (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:9895:15)
    at async Object.fflonkSetup [as action] (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:13688:12)
    at async clProcessor (/usr/local/lib/node_modules/snarkjs/build/cli.cjs:517:27)

~~~

### STDERR
~~~

~~~


# snarkjs-vkey

  * command: `/usr/local/bin/snarkjs zkey export verificationkey /tmp/circom-1/explore/working/transformed/groth16_final.zkey /tmp/circom-1/explore/working/transformed/groth16_vkey.json`
  * time: `1.0361955165863037s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: EXPORT VERIFICATION KEY STARTED
[INFO]  snarkJS: > Detected protocol: groth16
[INFO]  snarkJS: EXPORT VERIFICATION KEY FINISHED

~~~

### STDERR
~~~

~~~

