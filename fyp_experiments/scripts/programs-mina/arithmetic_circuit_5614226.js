import { Field, Bool, Provable, ZkProgram, Struct } from 'o1js';
class CircuitOutput extends Struct({ out0: Field, out1: Field, out2: Field }) {
}
const circuit = ZkProgram({
    name: 'circuit_A1EBAAT7GY',
    publicOutput: CircuitOutput,
    methods: {
        compute: {
            privateInputs: [Field, Field, Field, Field],
            async method(in0, in1, in2, in3) {
                const out0 = in2;
                Provable.log(out0);
                const out1 = Provable.if(Bool(false).not(), Field(0), out0);
                Provable.log(out1);
                const out2 = Field(8595464904590290836399900583982998929300673037232307746983095412740812846323n);
                Provable.log(out2);
                Bool(false).or(Bool(false)).and(Bool(true).not()).assertTrue();
                out1.div(Field(17157183666151086547122977390345470201300820833285191504114659764635996245716n)).equals(Provable.if(Bool(false), Field(21888242871839275222246405745257275088548364400416034343698204186575808495617n), Field(11275153710672208502740953831256614498544143471789329806343213785987153311635n))).assertTrue();
                return new CircuitOutput({ out0, out1, out2 });
            },
        }
    },
});
export { circuit };
