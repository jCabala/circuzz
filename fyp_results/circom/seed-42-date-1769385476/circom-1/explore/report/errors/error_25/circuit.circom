pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal output out0;
    signal output out1;
    component comp_0 = NOT();
    comp_0.in <== 0;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
    signal sig_2;
    sig_2 <== (- 18446744069414584321);
    signal sig_3;
    sig_3 <== (- 0);
    component comp_4 = GreaterEqThan(252);
    comp_4.in[0] <== sig_2;
    comp_4.in[1] <== sig_3;
    component comp_5 = Mux1();
    comp_5.c[0] <== comp_4.out;
    comp_5.c[1] <== comp_1.out;
    comp_5.s <== 0;
    signal sig_6;
    sig_6 <-- (0 / 10111827412341285182);
    (sig_6 * 10111827412341285182) === 0;
    signal sig_7;
    sig_7 <-- (~ 18446744069414584321);
    signal sig_8;
    sig_8 <-- ((- sig_6) | sig_7);
    component comp_9 = Mux1();
    comp_9.c[0] <== sig_8;
    comp_9.c[1] <== 0;
    comp_9.s <== comp_5.out;
    out0 <== comp_9.out;
    component comp_10 = Mux1();
    comp_10.c[0] <== out0;
    comp_10.c[1] <== out0;
    comp_10.s <== 1;
    signal sig_11;
    sig_11 <== comp_10.out;
    signal sig_12;
    sig_12 <== (sig_11 * sig_11);
    signal sig_13;
    sig_13 <== (- 0);
    component comp_14 = LessThan(252);
    comp_14.in[0] <== sig_13;
    comp_14.in[1] <== sig_12;
    signal sig_15;
    sig_15 <-- (14828397073512385120 | 12045138392652411232);
    signal sig_16;
    sig_16 <-- ((- sig_15) % 18446744069414584320);
    component comp_17 = Mux1();
    comp_17.c[0] <== out0;
    comp_17.c[1] <== out0;
    comp_17.s <== 0;
    signal sig_18;
    sig_18 <== comp_17.out;
    signal sig_19;
    sig_19 <== (sig_18 * sig_18);
    signal sig_20;
    sig_20 <== (sig_19 * sig_18);
    signal sig_21;
    sig_21 <-- (~ sig_20);
    component comp_22 = Mux1();
    comp_22.c[0] <== sig_21;
    comp_22.c[1] <== sig_16;
    comp_22.s <== comp_14.out;
    out1 <== comp_22.out;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
