pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal sig_0;
    sig_0 <== 1;
    signal sig_1;
    sig_1 <== 50512609154787507583848742153051857203944869806401642645927836977501624938267;
    component comp_2 = LessThan(252);
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    component comp_3 = OR();
    comp_3.a <== 0;
    comp_3.b <== 0;
    component comp_4 = AND();
    comp_4.a <== 0;
    comp_4.b <== 0;
    component comp_5 = Mux1();
    comp_5.c[0] <== comp_4.out;
    comp_5.c[1] <== comp_3.out;
    comp_5.s <== comp_2.out;
    component comp_6 = Mux1();
    comp_6.c[0] <== 0;
    comp_6.c[1] <== 1;
    comp_6.s <== 0;
    component comp_7 = Mux1();
    comp_7.c[0] <== 51301167069906104612100990430439040234809270675372039976166714510581515383959;
    comp_7.c[1] <== (- 52435875175126190479447740508185965837690552500527637822603658699938581184512);
    comp_7.s <== comp_6.out;
    component comp_8 = Mux1();
    comp_8.c[0] <== (- in0);
    comp_8.c[1] <== comp_7.out;
    comp_8.s <== comp_5.out;
    signal sig_9;
    sig_9 <== comp_8.out;
    signal sig_10;
    sig_10 <== 27053047593864326150797854648138019294266430679097529204766491364048929000370;
    component comp_11 = IsEqual();
    comp_11.in[0] <== sig_9;
    comp_11.in[1] <== sig_10;
    component comp_12 = NOT();
    comp_12.in <== comp_11.out;
    component comp_13 = IsZero();
    comp_13.in <== comp_12.out;
    component comp_14 = NOT();
    comp_14.in <== comp_13.out;
comp_14.out === 1;
}

component main = main_template();
