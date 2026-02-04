pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal output out0;
    out0 <== in0;
    signal sig_0;
    sig_0 <== 0;
    component comp_1 = IsEqual();
    comp_1.in[0] <== in0;
    comp_1.in[1] <== sig_0;
    component comp_2 = NOT();
    comp_2.in <== comp_1.out;
    component comp_3 = AND();
    comp_3.a <== 1;
    comp_3.b <== 0;
    component comp_4 = OR();
    comp_4.a <== comp_2.out;
    comp_4.b <== comp_3.out;
    component comp_5 = NOT();
    comp_5.in <== comp_4.out;
    component comp_6 = OR();
    comp_6.a <== 0;
    comp_6.b <== 0;
    component comp_7 = NOT();
    comp_7.in <== comp_6.out;
    component comp_8 = NOT();
    comp_8.in <== 0;
    component comp_9 = NOT();
    comp_9.in <== comp_8.out;
    component comp_10 = NOT();
    comp_10.in <== 1;
    component comp_11 = NOT();
    comp_11.in <== comp_10.out;
    component comp_12 = Mux1();
    comp_12.c[0] <== comp_11.out;
    comp_12.c[1] <== comp_9.out;
    comp_12.s <== comp_7.out;
    component comp_13 = GreaterEqThan(252);
    comp_13.in[0] <== in0;
    comp_13.in[1] <== in0;
    component comp_14 = NOT();
    comp_14.in <== comp_13.out;
    component comp_15 = NOT();
    comp_15.in <== comp_14.out;
    component comp_16 = Mux1();
    comp_16.c[0] <== comp_15.out;
    comp_16.c[1] <== comp_12.out;
    comp_16.s <== comp_5.out;
    component comp_17 = IsZero();
    comp_17.in <== comp_16.out;
    component comp_18 = NOT();
    comp_18.in <== comp_17.out;
comp_18.out === 1;
    log("<@> out0 = ", out0);
}

component main = main_template();
