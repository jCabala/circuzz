pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = IsZero();
    comp_0.in <== 1;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
comp_1.out === 1;
}

component main = main_template();
