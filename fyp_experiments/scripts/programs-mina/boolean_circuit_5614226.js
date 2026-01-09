import { Bool, Provable, ZkProgram } from 'o1js';
const circuit = ZkProgram({
    name: 'circuit_GYA1EBAAT7',
    publicOutput: Bool,
    methods: {
        compute: {
            privateInputs: [Bool, Bool, Bool, Bool],
            async method(in0, in1, in2, in3) {
                const out0 = in2;
                Provable.log(out0);
                const out1 = Provable.if(Bool(false).not(), Bool(true), Bool(true).not());
                Provable.log(out1);
                const out2 = Provable.if(out0, in2, in0).equals(Bool(false).or(in3));
                Provable.log(out2);
                Bool(true).equals(out1).or(Provable.if(Bool(false), out0, Bool(true))).assertTrue();
                Provable.if(Bool(false).equals(in2), Bool(true).and(in2), out2.and(Bool(false))).assertTrue();
                return out0;
            },
        }
    },
});
export { circuit };
