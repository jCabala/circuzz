pragma circom 2.0.6;

template main_template() {
    signal x;
    x <== 1;
}

component main = main_template();
