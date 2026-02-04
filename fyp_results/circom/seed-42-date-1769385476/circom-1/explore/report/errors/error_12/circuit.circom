pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    component comp_0 = NOT();
    comp_0.in <== 1;
    component comp_1 = NOT();
    comp_1.in <== 1;
    component comp_2 = XOR();
    comp_2.a <== comp_0.out;
    comp_2.b <== comp_1.out;
    component comp_3 = AND();
    comp_3.a <== comp_2.out;
    comp_3.b <== 1;
    component comp_4 = NOT();
    comp_4.in <== 1;
    signal sig_5;
    sig_5 <-- (18986625362143384316802301637283182340004191978101354240217865291145553825840 / 21550292909495742128435558210718863350036425733556904979810251539507720852798);
    (sig_5 * 21550292909495742128435558210718863350036425733556904979810251539507720852798) === 18986625362143384316802301637283182340004191978101354240217865291145553825840;
    component comp_6 = Mux1();
    comp_6.c[0] <== (1068551689802710595130187880760537918830323262618448513151792565340221041889 - in0);
    comp_6.c[1] <== sig_5;
    comp_6.s <== comp_4.out;
    signal sig_7;
    sig_7 <== (10804616679935883894251534103937494052014284341676179100613187292602718192019 - 14545230348457293280311543067122425678176447081844074179326471003164175040972);
    signal sig_8;
    sig_8 <== comp_6.out;
    component comp_9 = IsEqual();
    comp_9.in[0] <== sig_7;
    comp_9.in[1] <== sig_8;
    component comp_10 = NOT();
    comp_10.in <== comp_9.out;
    component comp_11 = XOR();
    comp_11.a <== comp_3.out;
    comp_11.b <== comp_10.out;
    component comp_12 = IsZero();
    comp_12.in <== comp_11.out;
    component comp_13 = NOT();
    comp_13.in <== comp_12.out;
comp_13.out === 1;
}

component main = main_template();
