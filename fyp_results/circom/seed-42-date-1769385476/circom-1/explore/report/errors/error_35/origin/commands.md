
# circom-compile

  * command: `/root/.cargo/bin/circom --output /tmp/circom-1/explore/working/origin --r1cs --sym --wasm --c --json --prime goldilocks --O0 -l /circuzz/circomlib/circuits /tmp/circom-1/explore/working/origin/circuit.circom`
  * time: `0.08109283447265625s`
  * returncode: `0`

### STDOUT
~~~
template instances: 9
non-linear constraints: 510
linear constraints: 42
public inputs: 0
private inputs: 1
public outputs: 2
wires: 551
labels: 551
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
  * time: `6.275751352310181s`
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
  * time: `0.00359344482421875s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  1547794799609807648
<@> out1 =  1486251149774598504

~~~

### STDERR
~~~

~~~


# circom-witness-nodejs

  * command: `/usr/bin/node /tmp/circom-1/explore/working/origin/circuit_js/generate_witness.js /tmp/circom-1/explore/working/origin/circuit_js/circuit.wasm /tmp/circom-1/explore/working/origin/input.json /tmp/circom-1/explore/working/origin/witness.js.wtns`
  * time: `0.19561195373535156s`
  * returncode: `0`

### STDOUT
~~~
<@> out0 =  1547794799609807648
<@> out1 =  1486251149774598504

~~~

### STDERR
~~~

~~~

