
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime bn128 --O1 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.06355428695678711s`
  * returncode: `0`

### STDOUT
~~~
template instances: 3
non-linear constraints: 0
linear constraints: 3
public inputs: 0
private inputs: 1 (none belong to witness)
public outputs: 0
wires: 3
labels: 7
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
  * time: `0.15433597564697266s`
  * returncode: `0`

### STDOUT
~~~

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs fflonk setup /tmp/circom-1/explore/working/origin/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/origin/fflonk_final.zkey`
  * time: `1.0946574211120605s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: FFLONK SETUP STARTED
[INFO]  snarkJS: > Reading PTau file
[INFO]  snarkJS: > Getting curve from PTau settings
[INFO]  snarkJS: > Reading r1cs file
[INFO]  snarkJS: > Processing FFlonk constraints
[INFO]  snarkJS: ----------------------------
[INFO]  snarkJS:   FFLONK SETUP SETTINGS
[INFO]  snarkJS:   Curve:         bn128
[INFO]  snarkJS:   Circuit power: 3
[INFO]  snarkJS:   Domain size:   8
[INFO]  snarkJS:   Vars:          3
[INFO]  snarkJS:   Public vars:   0
[INFO]  snarkJS:   Constraints:   3
[INFO]  snarkJS:   Additions:     0
[INFO]  snarkJS: ----------------------------
[INFO]  snarkJS: > computing k1 and k2
[INFO]  snarkJS: > computing w3
[INFO]  snarkJS: > computing w4
[INFO]  snarkJS: > computing w8
[INFO]  snarkJS: > computing wr
[INFO]  snarkJS: > Writing the zkey file
[INFO]  snarkJS: ··· Writing Section 1. Zkey Header
[INFO]  snarkJS: ··· Writing Section 3. Additions
[INFO]  snarkJS: ··· Writing Section 4. A Map
[INFO]  snarkJS: ··· Writing Section 5. B Map
[INFO]  snarkJS: ··· Writing Section 6. C Map
[INFO]  snarkJS: ··· Writing Section 7. QL
[INFO]  snarkJS: ··· Writing Section 8. QR
[INFO]  snarkJS: ··· Writing Section 9. QM
[INFO]  snarkJS: ··· Writing Section 10. QO
[INFO]  snarkJS: ··· Writing Section 11. QC
[INFO]  snarkJS: ··· Writing Sections 12,13,14. Sigma1, Sigma2 & Sigma 3
[INFO]  snarkJS: ··· Writing Section 15. Lagrange Polynomials
[INFO]  snarkJS: ··· Writing Section 16. Powers of Tau
[INFO]  snarkJS: ··· Writing Section 17. C0
[INFO]  snarkJS: ··· Writing Section 2. FFlonk Header
[INFO]  snarkJS: > Writing the zkey file finished
[INFO]  snarkJS: FFLONK SETUP FINISHED

~~~

### STDERR
~~~

~~~


# snarkjs-zkey

  * command: `/usr/local/bin/snarkjs plonk setup /tmp/circom-1/explore/working/origin/circuit.r1cs /circuzz/ptaus/powersOfTau28_hez_final_17.ptau /tmp/circom-1/explore/working/origin/plonk_final.zkey`
  * time: `1.616910457611084s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: Reading r1cs
[INFO]  snarkJS: Plonk constraints: 3
[INFO]  snarkJS: Setup Finished

~~~

### STDERR
~~~

~~~


# snarkjs-vkey

  * command: `/usr/local/bin/snarkjs zkey export verificationkey /tmp/circom-1/explore/working/origin/fflonk_final.zkey /tmp/circom-1/explore/working/origin/fflonk_vkey.json`
  * time: `0.9443435668945312s`
  * returncode: `0`

### STDOUT
~~~
[INFO]  snarkJS: EXPORT VERIFICATION KEY STARTED
[INFO]  snarkJS: > Detected protocol: fflonk
[INFO]  snarkJS: EXPORT VERIFICATION KEY FINISHED

~~~

### STDERR
~~~

~~~


# snarkjs-prove

  * command: `/usr/local/bin/snarkjs plonk prove /tmp/circom-1/explore/working/origin/plonk_final.zkey /tmp/circom-1/explore/working/origin/witness.js.wtns /tmp/circom-1/explore/working/origin/proof.json /tmp/circom-1/explore/working/origin/public.json`
  * time: `1.0669982433319092s`
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

