pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = Mux1();
    comp_0.c[0] <== 0;
    comp_0.c[1] <== 115792089210356248762697446949407573530086143415290314195533631308867097853951;
    comp_0.s <== 0;
    signal sig_1;
    sig_1 <== comp_0.out;
    component comp_2 = IsEqual();
    comp_2.in[0] <== in0;
    comp_2.in[1] <== sig_1;
    component comp_3 = NOT();
    comp_3.in <== comp_2.out;
    component comp_4 = AND();
    comp_4.a <== comp_3.out;
    comp_4.b <== 0;
    component comp_5 = NOT();
    comp_5.in <== comp_4.out;
    component comp_6 = IsZero();
    comp_6.in <== comp_5.out;
    component comp_7 = NOT();
    comp_7.in <== comp_6.out;
comp_7.out === 1;
}

component main = main_template();
