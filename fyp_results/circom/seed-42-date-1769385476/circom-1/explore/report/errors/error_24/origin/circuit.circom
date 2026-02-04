pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = GreaterThan(252);
    comp_0.in[0] <== in0;
    comp_0.in[1] <== in0;
    component comp_1 = NOT();
    comp_1.in <== 1;
    component comp_2 = OR();
    comp_2.a <== comp_0.out;
    comp_2.b <== comp_1.out;
    component comp_3 = AND();
    comp_3.a <== 1;
    comp_3.b <== 0;
    component comp_4 = IsEqual();
    comp_4.in[0] <== in0;
    comp_4.in[1] <== in0;
    component comp_5 = NOT();
    comp_5.in <== comp_4.out;
    component comp_6 = OR();
    comp_6.a <== comp_3.out;
    comp_6.b <== comp_5.out;
    component comp_7 = AND();
    comp_7.a <== comp_2.out;
    comp_7.b <== comp_6.out;
    component comp_8 = Mux1();
    comp_8.c[0] <== 1;
    comp_8.c[1] <== 0;
    comp_8.s <== comp_7.out;
    component comp_9 = IsZero();
    comp_9.in <== comp_8.out;
    component comp_10 = NOT();
    comp_10.in <== comp_9.out;
comp_10.out === 1;
}

component main = main_template();
