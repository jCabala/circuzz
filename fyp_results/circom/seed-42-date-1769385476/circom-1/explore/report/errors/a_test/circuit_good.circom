pragma circom 2.2.3;

template main_template() {
    signal input in0;
    assert(in0 == 15);
    assert(in0 < 23);
}

component main = main_template();
