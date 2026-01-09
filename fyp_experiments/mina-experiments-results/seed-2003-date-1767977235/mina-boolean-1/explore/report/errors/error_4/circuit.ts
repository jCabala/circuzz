import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = Bool(true);
        Provable.log(out0);
        out0.not().assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
