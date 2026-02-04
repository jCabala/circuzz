pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = Mux1();
    comp_0.c[0] <== 0;
    comp_0.c[1] <== 0;
    comp_0.s <== 1;
    component comp_1 = Mux1();
    comp_1.c[0] <== in0;
    comp_1.c[1] <== 47791122111176356254920037258366877785650943861412989372538817037387675394404;
    comp_1.s <== 0;
    component comp_2 = Mux1();
    comp_2.c[0] <== comp_1.out;
    comp_2.c[1] <== 0;
    comp_2.s <== comp_0.out;
    signal sig_3;
    sig_3 <== comp_2.out;
    component comp_4 = LessThan(252);
    comp_4.in[0] <== sig_3;
    comp_4.in[1] <== in0;
    component comp_5 = NOT();
    comp_5.in <== comp_4.out;
    component comp_6 = IsZero();
    comp_6.in <== comp_5.out;
    component comp_7 = NOT();
    comp_7.in <== comp_6.out;
comp_7.out === 1;
    component comp_8 = IsZero();
    comp_8.in <== 1;
    component comp_9 = NOT();
    comp_9.in <== comp_8.out;
comp_9.out === 1;
}

component main = main_template();
