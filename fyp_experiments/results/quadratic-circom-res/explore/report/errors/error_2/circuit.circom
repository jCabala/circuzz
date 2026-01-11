pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

template main_template() {
    signal input in0;
    signal output out0;
    out0 <== in0;
    (((out0 * 1) * (out0 * 60062529058419375718566958237820686467046721409727566615356368990663003606570)) + (out0 * 6581065076463509253949221702752451799824096799386719071933881576783507035165)) === 0;
    log("<@> out0 = ", out0);
}

component main = main_template();
