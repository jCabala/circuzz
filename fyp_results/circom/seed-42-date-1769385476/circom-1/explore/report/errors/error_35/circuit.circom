pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal output out0;
    signal output out1;
    out0 <== (- 16898949269804776673);
    out1 <== in0;
    signal sig_0;
    sig_0 <== 0;
    signal sig_1;
    sig_1 <== 14727475742939953530;
    component comp_2 = GreaterEqThan(252);
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    component comp_3 = NOT();
    comp_3.in <== 0;
    component comp_4 = Mux1();
    comp_4.c[0] <== comp_3.out;
    comp_4.c[1] <== 0;
    comp_4.s <== comp_2.out;
    component comp_5 = Mux1();
    comp_5.c[0] <== (- (- 7761042409611639294));
    comp_5.c[1] <== 1645597081163114969;
    comp_5.s <== comp_4.out;
    signal sig_6;
    sig_6 <== comp_5.out;
    signal sig_7;
    sig_7 <== 13162773539536675389;
    component comp_8 = LessEqThan(252);
    comp_8.in[0] <== sig_6;
    comp_8.in[1] <== sig_7;
    component comp_9 = IsZero();
    comp_9.in <== comp_8.out;
    component comp_10 = NOT();
    comp_10.in <== comp_9.out;
comp_10.out === 1;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
