pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal output out0;
    signal output out1;
    out0 <== (- 19090816565666797321879841602370540325468434764063686785984935538106013817548);
    out1 <== in0;
    component comp_0 = NOT();
    comp_0.in <== 1;
    component comp_1 = IsZero();
    comp_1.in <== comp_0.out;
    component comp_2 = NOT();
    comp_2.in <== comp_1.out;
comp_2.out === 1;
    component comp_3 = Mux1();
    comp_3.c[0] <== in0;
    comp_3.c[1] <== 17161288594002055393003212971962006297144060666840898558927154726071136407433;
    comp_3.s <== 0;
    component comp_4 = Mux1();
    comp_4.c[0] <== (28948022309329048855892746252171976963363056481941560715954676764349967630336 - 28948022309329048855892746252171976963363056481941560715954676764349967630337);
    comp_4.c[1] <== comp_3.out;
    comp_4.s <== 1;
    signal sig_5;
    sig_5 <== comp_4.out;
    signal sig_6;
    sig_6 <== ((- 11239943947683144285653751741432687205128787640313205898995146788002603908217) * in1);
    component comp_7 = IsEqual();
    comp_7.in[0] <== sig_5;
    comp_7.in[1] <== sig_6;
    component comp_8 = NOT();
    comp_8.in <== comp_7.out;
    component comp_9 = IsZero();
    comp_9.in <== comp_8.out;
    component comp_10 = NOT();
    comp_10.in <== comp_9.out;
comp_10.out === 1;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
