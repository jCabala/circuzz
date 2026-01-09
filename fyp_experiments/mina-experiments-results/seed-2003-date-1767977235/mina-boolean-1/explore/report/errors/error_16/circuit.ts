import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in1;
        Provable.log(out0);
        Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false), in1.or(in1).and(out0.and(Bool(true))))).assertTrue();
        Bool(true).not().assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
