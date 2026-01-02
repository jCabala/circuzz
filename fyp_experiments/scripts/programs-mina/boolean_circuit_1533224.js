import { Bool, Provable, ZkProgram } from 'o1js';
const circuit = ZkProgram({
    name: 'circuit_8S1W7AW4G5',
    publicOutput: Bool,
    methods: {
        compute: {
            privateInputs: [Bool, Bool],
            async method(in0, in1) {
                const out0 = Bool(false);
                Provable.log(out0);
                in0.equals(Bool(true)).not().assertTrue();
                Bool(true).assertTrue();
                in1.not().and(out0.equals(Bool(false))).assertTrue();
                return out0;
            },
        }
    },
});
export { circuit };
