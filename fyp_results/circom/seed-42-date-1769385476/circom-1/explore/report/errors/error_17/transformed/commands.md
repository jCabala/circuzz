
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bn128 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `2.604957342147827s`
  * returncode: `0`

### STDOUT
~~~
template instances: 13
non-linear constraints: 13474
linear constraints: 342
public inputs: 0
private inputs: 1
public outputs: 0
wires: 13773
labels: 22044
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


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/transformed/circuit_js/generate_witness.js /tmp/circom-1/explore/working/transformed/circuit_js/circuit.wasm /tmp/circom-1/explore/working/transformed/input.json /tmp/circom-1/explore/working/transformed/witness.js.wtns`
  * time: `0.3120601177215576s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs fflonk setup /tmp/circom-1/explore/working/transformed/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/transformed/fflonk_final.zkey`
  * time: `1.5268127918243408s`
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

