pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    component comp_0 = XOR();
    comp_0.a <== 1;
    comp_0.b <== 0;
    component comp_1 = NOT();
    comp_1.in <== 0;
    component comp_2 = OR();
    comp_2.a <== comp_0.out;
    comp_2.b <== comp_1.out;
    component comp_3 = GreaterEqThan(252);
    comp_3.in[0] <== in1;
    comp_3.in[1] <== in1;
    component comp_4 = NOT();
    comp_4.in <== comp_3.out;
    component comp_5 = Mux1();
    comp_5.c[0] <== comp_4.out;
    comp_5.c[1] <== 1;
    comp_5.s <== comp_2.out;
    component comp_6 = OR();
    comp_6.a <== comp_5.out;
    comp_6.b <== 0;
    component comp_7 = IsZero();
    comp_7.in <== comp_6.out;
    component comp_8 = NOT();
    comp_8.in <== comp_7.out;
comp_8.out === 1;
}

component main = main_template();
