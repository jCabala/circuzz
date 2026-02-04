pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal output out0;
    signal output out1;
    out0 <== in0;
    component comp_0 = NOT();
    comp_0.in <== 0;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
    signal sig_2;
    sig_2 <== 1;
    component comp_3 = GreaterEqThan(252);
    comp_3.in[0] <== out0;
    comp_3.in[1] <== sig_2;
    component comp_4 = XOR();
    comp_4.a <== 0;
    comp_4.b <== 1;
    component comp_5 = OR();
    comp_5.a <== comp_3.out;
    comp_5.b <== comp_4.out;
    component comp_6 = OR();
    comp_6.a <== comp_1.out;
    comp_6.b <== comp_5.out;
    component comp_7 = GreaterEqThan(252);
    comp_7.in[0] <== out0;
    comp_7.in[1] <== out0;
    signal sig_8;
    sig_8 <-- (~ 1);
    signal sig_9;
    sig_9 <-- (~ out0);
    component comp_10 = Mux1();
    comp_10.c[0] <== sig_9;
    comp_10.c[1] <== sig_8;
    comp_10.s <== comp_7.out;
    signal sig_11;
    sig_11 <-- (in0 / 8562679397594381875);
    (sig_11 * 8562679397594381875) === in0;
    component comp_12 = Mux1();
    comp_12.c[0] <== 10533494783209362882;
    comp_12.c[1] <== out0;
    comp_12.s <== 0;
    component comp_13 = Mux1();
    comp_13.c[0] <== comp_12.out;
    comp_13.c[1] <== sig_11;
    comp_13.s <== 0;
    signal sig_14;
    sig_14 <-- ((- 14811239671300772901) & (5247613925312444266 * out0));
    component comp_15 = Mux1();
    comp_15.c[0] <== (comp_13.out * sig_14);
    comp_15.c[1] <== ((- 12907764452068141885) - comp_10.out);
    comp_15.s <== comp_6.out;
    out1 <== comp_15.out;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
