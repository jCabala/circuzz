pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal sig_0;
    sig_0 <== 6790476057423968248241286203903640015006626353258349417173146728411431579043;
    signal sig_1;
    sig_1 <== 0;
    component comp_2 = GreaterEqThan(252);
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    component comp_3 = Mux1();
    comp_3.c[0] <== 1;
    comp_3.c[1] <== 1;
    comp_3.s <== 1;
    component comp_4 = Mux1();
    comp_4.c[0] <== comp_3.out;
    comp_4.c[1] <== 0;
    comp_4.s <== comp_2.out;
    signal sig_5;
    sig_5 <== 0;
    signal sig_6;
    sig_6 <== (- 45737840190531646818754261017238053336108477884271291126744993401256215696057);
    component comp_7 = LessEqThan(252);
    comp_7.in[0] <== sig_5;
    comp_7.in[1] <== sig_6;
    component comp_8 = AND();
    comp_8.a <== comp_4.out;
    comp_8.b <== comp_7.out;
    component comp_9 = NOT();
    comp_9.in <== comp_8.out;
    component comp_10 = IsZero();
    comp_10.in <== comp_9.out;
    component comp_11 = NOT();
    comp_11.in <== comp_10.out;
comp_11.out === 1;
}

component main = main_template();
