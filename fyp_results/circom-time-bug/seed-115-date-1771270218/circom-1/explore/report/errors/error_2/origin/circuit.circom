pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

include "/circuzz/circomlib/circuits/mux1.circom";

include "/circuzz/circomlib/circuits/gates.circom";

template main_template() {
    signal output out0;
    signal output out1;
    out0 <== (1 ** 3);
    signal sig_0;
    sig_0 <== (- 19003304742822668421115438173807945795880977952579406613649193514185472502643);
    signal sig_1;
    sig_1 <== ((- 19633416031436435576808773938673870459113305783943123190973530912853114573980) ** 2);
    component comp_2 = IsEqual();
    comp_2.in[0] <== sig_0;
    comp_2.in[1] <== sig_1;
    component comp_3 = Mux1();
    comp_3.c[0] <== 11562657440471140539572780724882947749716043319767592859943890343305240056796;
    comp_3.c[1] <== 6791041259975047677696173229071241898553666671294066611237383914801964260261;
    comp_3.s <== comp_2.out;
    out1 <== comp_3.out;
    component comp_4 = Mux1();
    comp_4.c[0] <== 586437751505311589287875108786085234281046184895602650681625187557819658096;
    comp_4.c[1] <== 6287280589282957832509107933970688268990813118085045396592560524082073136584;
    comp_4.s <== 1;
    component comp_5 = Mux1();
    comp_5.c[0] <== comp_4.out;
    comp_5.c[1] <== (10559020776422660113925237905461049257758068016410518951388055056496632176166 * 21767599482019396851686831872732237068836162487896498776933918083585354105877);
    comp_5.s <== 1;
    signal sig_6;
    sig_6 <== comp_5.out;
    component comp_7 = IsEqual();
    comp_7.in[0] <== sig_6;
    comp_7.in[1] <== out1;
    component comp_8 = NOT();
    comp_8.in <== comp_7.out;
    component comp_9 = Mux1();
    comp_9.c[0] <== (- 18888792868388801152129422264003653004171860698613184147686268652151932226083);
    comp_9.c[1] <== out1;
    comp_9.s <== 0;
    signal sig_10;
    sig_10 <== comp_9.out;
    signal sig_11;
    sig_11 <== (- out0);
    component comp_12 = IsEqual();
    comp_12.in[0] <== sig_10;
    comp_12.in[1] <== sig_11;
    component comp_13 = XOR();
    comp_13.a <== comp_8.out;
    comp_13.b <== comp_12.out;
    component comp_14 = IsZero();
    comp_14.in <== comp_13.out;
    component comp_15 = NOT();
    comp_15.in <== comp_14.out;
comp_15.out === 1;
    component comp_16 = XOR();
    comp_16.a <== 1;
    comp_16.b <== 1;
    component comp_17 = NOT();
    comp_17.in <== comp_16.out;
    component comp_18 = NOT();
    comp_18.in <== comp_17.out;
    component comp_19 = AND();
    comp_19.a <== comp_18.out;
    comp_19.b <== 1;
    component comp_20 = IsZero();
    comp_20.in <== comp_19.out;
    component comp_21 = NOT();
    comp_21.in <== comp_20.out;
comp_21.out === 1;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
