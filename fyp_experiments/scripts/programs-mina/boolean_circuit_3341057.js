import { Bool, Provable, ZkProgram } from 'o1js';
const circuit = ZkProgram({
    name: 'circuit_JOY4HTP0DC',
    publicOutput: Bool,
    methods: {
        compute: {
            privateInputs: [Bool, Bool, Bool],
            async method(in0, in1, in2) {
                const out0 = Bool(false).equals(Bool(true)).not();
                Provable.log(out0);
                Provable.if(Bool(false).equals(Bool(false)), in2.or(Bool(true)), in2.equals(Bool(true))).assertTrue();
                return out0;
            },
        }
    },
});
export { circuit };
