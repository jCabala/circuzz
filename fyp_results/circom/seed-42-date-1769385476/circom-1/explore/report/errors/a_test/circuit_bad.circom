pragma circom 2.2.3;

template main_template() {
    signal input in0;
    (in0 - 15) * (in0 - 16) === 0;
}

component main = main_template();
