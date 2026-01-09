import { Field, Bool, Provable, ZkProgram, Gadgets } from 'o1js';

const circuit = ZkProgram({
  name: 'circuit_54MJB30O8K',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool, Bool, Bool, Bool],
      async method(in0: Bool, in1: Bool, in2: Bool, in3: Bool) {
        const out0 = Bool(false);
        Provable.log(out0);
        const out1 = in1.not();
        Provable.log(out1);
        out1.or(in3.not()).assertTrue();
        return out0;
      },
    }
  },
})
export { circuit };
