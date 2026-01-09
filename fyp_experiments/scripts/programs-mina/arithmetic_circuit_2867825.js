import { Field, Bool, Provable, ZkProgram, Struct } from 'o1js';
class CircuitOutput extends Struct({ out0: Field, out1: Field }) {
}
const circuit = ZkProgram({
    name: 'circuit_J4EY0QJMRD',
    publicOutput: CircuitOutput,
    methods: {
        compute: {
            privateInputs: [Field, Field, Field, Field, Field],
            async method(in0, in1, in2, in3, in4) {
                const out0 = in2.sub(in4).add(in3.neg());
                Provable.log(out0);
                const out1 = Field(4040719051114297970887229637189198872395763217541225013712829721755523933176n);
                Provable.log(out1);
                Field(3527426304629211969444725556291368230723793505375684334767630523331536975135n).equals(Field(17670081981250921940200645509113182851769774974571239082368784217826032553779n)).not().assertTrue();
                Bool(false).assertTrue();
                Bool(true).assertTrue();
                return new CircuitOutput({ out0, out1 });
            },
        }
    },
});
export { circuit };
