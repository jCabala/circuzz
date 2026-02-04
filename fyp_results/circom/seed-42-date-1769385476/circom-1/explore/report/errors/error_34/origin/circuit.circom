pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal sig_0;
    sig_0 <== 66974223807482836615349492943395135951386561061403165775457149330856550778158;
    component comp_1 = IsEqual();
    comp_1.in[0] <== in1;
    comp_1.in[1] <== sig_0;
    component comp_2 = NOT();
    comp_2.in <== comp_1.out;
    component comp_3 = OR();
    comp_3.a <== 0;
    comp_3.b <== comp_2.out;
    component comp_4 = NOT();
    comp_4.in <== 1;
    signal sig_5;
    sig_5 <== 287740550977727481424115279249576073978149266290284008170877319227756348047;
    component comp_6 = LessEqThan(252);
    comp_6.in[0] <== in0;
    comp_6.in[1] <== sig_5;
    component comp_7 = Mux1();
    comp_7.c[0] <== comp_6.out;
    comp_7.c[1] <== comp_4.out;
    comp_7.s <== 0;
    component comp_8 = AND();
    comp_8.a <== comp_3.out;
    comp_8.b <== comp_7.out;
    component comp_9 = OR();
    comp_9.a <== comp_8.out;
    comp_9.b <== 1;
    component comp_10 = IsZero();
    comp_10.in <== comp_9.out;
    component comp_11 = NOT();
    comp_11.in <== comp_10.out;
comp_11.out === 1;
}

component main = main_template();
