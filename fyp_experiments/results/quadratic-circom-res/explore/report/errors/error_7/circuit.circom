pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal output out0;
    out0 <-- in0;
    (((out0 * 949980971180154289739942803838365873966441238216233471789284842696427492052) * (out0 * 28850913382685060518395595236778260786763560997002274693060579273325474119927)) + (out0 * 1)) === 0;
    log("<@> out0 = ", out0);
}

component main = main_template();
