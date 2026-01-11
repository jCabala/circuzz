pragma circom 2.0.6;

include "/circuzz/circomlib/circuits/comparators.circom";

template main_template() {
    signal input in0;
    signal input in1;
    signal output out0;
    signal output out1;
    out0 <== (in0 + in1);

    component ineq_0 = LessThan(252);
    ineq_0.in[0] <== (((out0 - in1) * 1) + ((out0 - in0) * 2825577164405848492059205542677236452156587383846700397814630208728464191287));
    ineq_0.in[1] <== 0;
    ineq_0.out === 1;

    out1 <-- in1;
    (((out1 * 19273961624529761569456234285031673396662107326491548728152035481664635906790) * (out1 * 1751459217619226820065055006266600416688108842945940264108539565098247049953)) + (out1 * 6391994107751712837873324491405209648969736796114961417949801615336838579027)) === 0;
    log("<@> out0 = ", out0);
    log("<@> out1 = ", out1);
}

component main = main_template();
