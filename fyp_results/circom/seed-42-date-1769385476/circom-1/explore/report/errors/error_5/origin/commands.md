
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime bn128 --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.694580078125s`
  * returncode: `0`

### STDOUT
~~~
template instances: 11
non-linear constraints: 3055
linear constraints: 1619
public inputs: 0
private inputs: 0
public outputs: 0
wires: 4664
labels: 4664
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


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/origin/circuit_js/generate_witness.js /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.js.wtns`
  * time: `0.17571568489074707s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs plonk setup /tmp/circom-1/explore/working/origin/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/origin/plonk_final.zkey`
  * time: `4.27321457862854s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: Reading r1cs
[INFO]  snarkJS: Plonk constraints: 8714
[INFO]  snarkJS: Setup Finished

~~~

### STDERR
~~~

~~~


# snarkjs-prove

  * command: `/usr/local/bin/snarkjs plonk prove /tmp/circom-1/explore/working/origin/plonk_final.zkey /tmp/circom-1/explore/working/origin/witness.js.wtns /tmp/circom-1/explore/working/origin/proof.json /tmp/circom-1/explore/working/origin/public.json`
  * time: `3.219724178314209s`
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

