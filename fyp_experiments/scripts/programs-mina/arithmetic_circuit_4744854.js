import { Field, Bool, Provable, ZkProgram, Struct } from 'o1js';
class CircuitOutput extends Struct({ out0: Field, out1: Field }) {
}
const circuit = ZkProgram({
    name: 'circuit_CMM5U8M0TM',
    publicOutput: CircuitOutput,
    methods: {
        compute: {
            privateInputs: [Field, Field, Field, Field],
            async method(in0, in1, in2, in3) {
                const out0 = Field(9296764117096784441151770936306076155520604309026890159605114659385629444688n).mul(in3).sub(in1.sub(Field(7855077458063169327990245473635503850673561003022208975456347870415936480701n)));
                Provable.log(out0);
                const out1 = in2.div(Field(2035396400099161614846027649100223500594019351120072155717322106837324129870n)).neg();
                Provable.log(out1);
                Bool(true).assertTrue();
                out0.equals(out1).not().assertTrue();
                return new CircuitOutput({ out0, out1 });
            },
        }
    },
});
export { circuit };
