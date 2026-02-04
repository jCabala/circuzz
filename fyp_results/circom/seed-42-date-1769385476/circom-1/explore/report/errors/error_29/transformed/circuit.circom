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
    component comp_3 = LessThan(252);
    comp_3.in[0] <== out0;
    comp_3.in[1] <== sig_2;
    component comp_4 = NOT();
    comp_4.in <== comp_3.out;
    component comp_5 = XOR();
    comp_5.a <== 0;
    comp_5.b <== 1;
    component comp_6 = XOR();
    comp_6.a <== 0;
    comp_6.b <== 1;
    component comp_7 = OR();
    comp_7.a <== comp_5.out;
    comp_7.b <== comp_6.out;
    component comp_8 = OR();
    comp_8.a <== comp_4.out;
    comp_8.b <== comp_7.out;
    component comp_9 = OR();
    comp_9.a <== comp_1.out;
    comp_9.b <== comp_8.out;
    component comp_10 = LessThan(252);
    comp_10.in[0] <== out0;
    comp_10.in[1] <== out0;
    component comp_11 = NOT();
    comp_11.in <== comp_10.out;
    signal sig_12;
    sig_12 <-- (~ 1);
    signal sig_13;
    sig_13 <-- (~ (out0 + 0));
    component comp_14 = Mux1();
    comp_14.c[0] <== sig_13;
    comp_14.c[1] <== sig_12;
    comp_14.s <== comp_11.out;
    signal sig_15;
    sig_15 <-- (in0 / 8562679397594381875);
    (sig_15 * 8562679397594381875) === in0;
    component comp_16 = Mux1();
    comp_16.c[0] <== 10533494783209362882;
    comp_16.c[1] <== out0;
    comp_16.s <== 0;
    component comp_17 = Mux1();
    comp_17.c[0] <== comp_16.out;
    comp_17.c[1] <== sig_15;
    comp_17.s <== 0;
    signal sig_18;
    sig_18 <-- ((- 14811239671300772901) & (5247613925312444266 * out0));
    component comp_19 = Mux1();
    comp_19.c[0] <== (comp_17.out * sig_18);
    comp_19.c[1] <== ((- 12907764452068141885) - comp_14.out);
    comp_19.s <== comp_9.out;
    signal sig_20;
    sig_20 <-- ((- (- comp_19.out)) / 1);
    (sig_20 * 1) === (- (- comp_19.out));
    out1 <== sig_20;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
