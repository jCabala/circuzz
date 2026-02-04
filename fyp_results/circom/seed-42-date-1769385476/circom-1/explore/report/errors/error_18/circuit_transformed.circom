pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    component comp_0 = AND();
    comp_0.a <== 0;
    comp_0.b <== 0;
    component comp_1 = OR();
    comp_1.a <== 1;
    comp_1.b <== comp_0.out;
    component comp_2 = AND();
    comp_2.a <== comp_1.out;
    comp_2.b <== 1;
    component comp_3 = OR();
    comp_3.a <== 1;
    comp_3.b <== 0;
    component comp_4 = OR();
    comp_4.a <== comp_2.out;
    comp_4.b <== comp_3.out;
    component comp_5 = XOR();
    comp_5.a <== 0;
    comp_5.b <== 0;
    component comp_6 = XOR();
    comp_6.a <== 0;
    comp_6.b <== 0;
    component comp_7 = AND();
    comp_7.a <== comp_5.out;
    comp_7.b <== comp_6.out;
    component comp_8 = OR();
    comp_8.a <== comp_7.out;
    comp_8.b <== 0;
    component comp_9 = OR();
    comp_9.a <== comp_4.out;
    comp_9.b <== comp_8.out;
    component comp_10 = AND();
    comp_10.a <== 1;
    comp_10.b <== comp_9.out;
    component comp_11 = IsZero();
    comp_11.in <== comp_10.out;
    component comp_12 = NOT();
    comp_12.in <== comp_11.out;
comp_12.out === 1;
}

component main = main_template();
