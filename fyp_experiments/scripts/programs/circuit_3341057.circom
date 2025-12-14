pragma circom 2.0.6;

template main_template() {
    signal input in0;
    signal input in1;
    signal input in2;
    signal output out0;
    out0 <== in1;
    (((out0 * 1) * (out0 * 2483218653743094201440698933207850725639861906677679905700372926024448914655)) + (out0 * 14345187935028818422352907530522563692353752569444145518126654208755687011983)) === 0;
    log("<@> out0 = ", out0);
}

component main = main_template();
