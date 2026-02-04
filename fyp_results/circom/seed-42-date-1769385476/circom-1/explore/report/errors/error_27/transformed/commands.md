
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/transformed --r1cs --sym --wasm --c --json --prime bn128 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/transformed/circuit.circom`
  * time: `2.7021324634552s`
  * returncode: `0`

### STDOUT
~~~
template instances: 15
non-linear constraints: 15760
linear constraints: 116
public inputs: 0
private inputs: 2 (1 belong to witness)
public outputs: 0
wires: 15827
labels: 25139
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
  * time: `0.2809262275695801s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs groth16 setup /tmp/circom-1/explore/working/transformed/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/transformed/groth16_final.zkey`
  * time: `7.7383434772491455s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: Reading r1cs
[INFO]  snarkJS: Reading tauG1
[INFO]  snarkJS: Reading tauG2
[INFO]  snarkJS: Reading alphatauG1
[INFO]  snarkJS: Reading betatauG1
[INFO]  snarkJS: Circuit hash: 
		21559881 6a74bcc5 ccd5bcb2 43ed987a
		535aa62f b805d72b 9b547c70 4e610e1f
		c3e4848a 862aa586 7133a3fd 35dca6f7
		4b2cd9ef 17fb99d7 74fc5bbb bd1bd081

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs fflonk setup /tmp/circom-1/explore/working/transformed/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/transformed/fflonk_final.zkey`
  * time: `1.5880062580108643s`
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
  * time: `0.8321311473846436s`
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

