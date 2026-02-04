pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

include "/circuzz/circomlib/circuits/bitify.circom";

template A(n) {
     assert(2**(n-1) > 0 && 2**(n) > 2**(n-1));

}

template main_template() {
    component a = A(62);
}

component main = main_template();
