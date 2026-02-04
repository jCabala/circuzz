pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal sig_0;
    sig_0 <== 17089319620709048622911045282384170041198792297248421937058727993792189886344;
    component comp_1 = IsEqual();
    comp_1.in[0] <== in1;
    comp_1.in[1] <== sig_0;
    component comp_2 = AND();
    comp_2.a <== 1;
    comp_2.b <== comp_1.out;
    component comp_3 = Mux1();
    comp_3.c[0] <== 0;
    comp_3.c[1] <== 1;
    comp_3.s <== 0;
    component comp_4 = Mux1();
    comp_4.c[0] <== 1;
    comp_4.c[1] <== comp_3.out;
    comp_4.s <== 0;
    component comp_5 = XOR();
    comp_5.a <== comp_2.out;
    comp_5.b <== comp_4.out;
    component comp_6 = Mux1();
    comp_6.c[0] <== 36930733788370166058998464993029686892067455594464570294380167632741746775509;
    comp_6.c[1] <== in1;
    comp_6.s <== 1;
    component comp_7 = Mux1();
    comp_7.c[0] <== in0;
    comp_7.c[1] <== 54032760618978632179028873823031300741641130432679172540593678772835497622631;
    comp_7.s <== 0;
    signal sig_8;
    sig_8 <== comp_6.out;
    signal sig_9;
    sig_9 <== comp_7.out;
    component comp_10 = GreaterThan(252);
    comp_10.in[0] <== sig_8;
    comp_10.in[1] <== sig_9;
    component comp_11 = Mux1();
    comp_11.c[0] <== 0;
    comp_11.c[1] <== 1;
    comp_11.s <== comp_10.out;
    component comp_12 = XOR();
    comp_12.a <== comp_5.out;
    comp_12.b <== comp_11.out;
    component comp_13 = IsZero();
    comp_13.in <== comp_12.out;
    component comp_14 = NOT();
    comp_14.in <== comp_13.out;
comp_14.out === 1;
}

component main = main_template();
