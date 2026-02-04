pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal sig_0;
    sig_0 <== 93774029552710340176927020533207663906119096939566085062647024789961405609793;
    signal sig_1;
    sig_1 <== 76447239051217741815101411541313895331547976478592547713285962986783344003944;
    component comp_2 = IsEqual();
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    component comp_3 = NOT();
    comp_3.in <== comp_2.out;
    component comp_4 = Mux1();
    comp_4.c[0] <== 0;
    comp_4.c[1] <== 1;
    comp_4.s <== 1;
    component comp_5 = AND();
    comp_5.a <== 0;
    comp_5.b <== 0;
    component comp_6 = Mux1();
    comp_6.c[0] <== comp_5.out;
    comp_6.c[1] <== comp_4.out;
    comp_6.s <== comp_3.out;
    component comp_7 = Mux1();
    comp_7.c[0] <== 0;
    comp_7.c[1] <== 1;
    comp_7.s <== 1;
    component comp_8 = AND();
    comp_8.a <== 0;
    comp_8.b <== 1;
    component comp_9 = Mux1();
    comp_9.c[0] <== comp_8.out;
    comp_9.c[1] <== comp_7.out;
    comp_9.s <== 0;
    component comp_10 = AND();
    comp_10.a <== comp_6.out;
    comp_10.b <== comp_9.out;
    component comp_11 = XOR();
    comp_11.a <== 1;
    comp_11.b <== comp_10.out;
    component comp_12 = IsZero();
    comp_12.in <== comp_11.out;
    component comp_13 = NOT();
    comp_13.in <== comp_12.out;
comp_13.out === 1;
}

component main = main_template();
