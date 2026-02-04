pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    component comp_0 = IsZero();
    comp_0.in <== 1;
    component comp_1 = NOT();
    comp_1.in <== comp_0.out;
comp_1.out === 1;
    signal sig_2;
    sig_2 <== 0;
    signal sig_3;
    sig_3 <== ((- (- 9715857475774716545735623286698087428880702377827750334489134655622772373527)) ** 3);
    component comp_4 = GreaterThan(252);
    comp_4.in[0] <== sig_2;
    comp_4.in[1] <== sig_3;
    component comp_5 = IsZero();
    comp_5.in <== comp_4.out;
    component comp_6 = NOT();
    comp_6.in <== comp_5.out;
comp_6.out === 1;
}

component main = main_template();
