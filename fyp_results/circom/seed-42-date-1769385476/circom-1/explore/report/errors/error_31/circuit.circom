pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal output out0;
    out0 <== 21888242871839275222246405745257275088548364400416034343698204186575808495616;
    component comp_0 = IsEqual();
    comp_0.in[0] <== in1;
    comp_0.in[1] <== in0;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
    component comp_2 = OR();
    comp_2.a <== 0;
    comp_2.b <== 1;
    component comp_3 = XOR();
    comp_3.a <== comp_1.out;
    comp_3.b <== comp_2.out;
    signal sig_4;
    sig_4 <== out0;
    signal sig_5;
    sig_5 <== (sig_4 * sig_4);
    signal sig_6;
    sig_6 <== sig_5;
    signal sig_7;
    sig_7 <== (sig_6 * sig_6);
    component comp_8 = Mux1();
    comp_8.c[0] <== (9619004568463390674220773941936406701878095908938953696901436575511323468395 - (out0 - 13265635599212112004225764320295868743455782104934116310483994009265182303246));
    comp_8.c[1] <== sig_7;
    comp_8.s <== comp_3.out;
    signal sig_9;
    sig_9 <== comp_8.out;
    component comp_10 = LessThan(252);
    comp_10.in[0] <== out0;
    comp_10.in[1] <== sig_9;
    component comp_11 = IsZero();
    comp_11.in <== comp_10.out;
    component comp_12 = NOT();
    comp_12.in <== comp_11.out;
comp_12.out === 1;
    log("<@> out0 = ", out0);
}

component main = main_template();
