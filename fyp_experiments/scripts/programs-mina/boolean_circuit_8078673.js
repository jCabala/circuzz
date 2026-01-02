import { Bool, Provable, ZkProgram, Struct } from 'o1js';
class CircuitOutput extends Struct({ out0: Bool, out1: Bool, out2: Bool }) {
}
const circuit = ZkProgram({
    name: 'circuit_ZSQFLWW00L',
    publicOutput: CircuitOutput,
    methods: {
        compute: {
            privateInputs: [Bool, Bool, Bool, Bool, Bool],
            async method(in0, in1, in2, in3, in4) {
                const out0 = Bool(false).not().equals(Provable.if(in0, Bool(true), Bool(false))).not();
                Provable.log(out0);
                const out1 = Bool(true).equals(Provable.if(in3, out0, Bool(false)));
                Provable.log(out1);
                const out2 = Bool(false).not();
                Provable.log(out2);
                Provable.if(Bool(false).not(), in2, out2.not()).assertTrue();
                Bool(true).equals(Bool(false)).not().assertTrue();
                Bool(false).assertTrue();
                return new CircuitOutput({ out0, out1, out2 });
            },
        }
    },
});
export { circuit };
