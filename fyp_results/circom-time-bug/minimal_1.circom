pragma circom 2.0.6;

template main_template() {
    signal output out0;
    signal output out1;
    out0 <== 1;
    out1 <== out0;
}

component main = main_template();
