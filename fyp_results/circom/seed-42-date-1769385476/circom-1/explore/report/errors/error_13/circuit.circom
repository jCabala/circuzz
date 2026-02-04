pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal output out0;
    signal sig_0;
    sig_0 <== 1890430877123251293;
    signal sig_1;
    sig_1 <== 10017450089846787151;
    component comp_2 = LessEqThan(252);
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    signal sig_3;
    sig_3 <== 5046601652994418491;
    signal sig_4;
    sig_4 <== 1678708292792433268;
    component comp_5 = IsEqual();
    comp_5.in[0] <== sig_3;
    comp_5.in[1] <== sig_4;
    component comp_6 = OR();
    comp_6.a <== comp_2.out;
    comp_6.b <== comp_5.out;
    component comp_7 = Mux1();
    comp_7.c[0] <== ((18446744069414584321 * 7580067349650763435) + 11450900877433446404);
    comp_7.c[1] <== 11047023035607765551;
    comp_7.s <== comp_6.out;
    signal sig_8;
    sig_8 <-- (comp_7.out / 15583005803237895103);
    (sig_8 * 15583005803237895103) === comp_7.out;
    out0 <== sig_8;
    log("<@> out0 = ", out0);
}

component main = main_template();
