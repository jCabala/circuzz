pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = NOT();
    comp_0.in <== 1;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
    component comp_2 = AND();
    comp_2.a <== 1;
    comp_2.b <== 1;
    component comp_3 = AND();
    comp_3.a <== comp_2.out;
    comp_3.b <== 0;
    component comp_4 = OR();
    comp_4.a <== comp_1.out;
    comp_4.b <== comp_3.out;
    component comp_5 = OR();
    comp_5.a <== 1;
    comp_5.b <== 1;
    component comp_6 = NOT();
    comp_6.in <== comp_5.out;
    component comp_7 = NOT();
    comp_7.in <== comp_6.out;
    component comp_8 = AND();
    comp_8.a <== 0;
    comp_8.b <== 1;
    component comp_9 = OR();
    comp_9.a <== comp_7.out;
    comp_9.b <== comp_8.out;
    component comp_10 = OR();
    comp_10.a <== comp_4.out;
    comp_10.b <== comp_9.out;
    component comp_11 = IsZero();
    comp_11.in <== comp_10.out;
    component comp_12 = NOT();
    comp_12.in <== comp_11.out;
comp_12.out === 1;
}

component main = main_template();
