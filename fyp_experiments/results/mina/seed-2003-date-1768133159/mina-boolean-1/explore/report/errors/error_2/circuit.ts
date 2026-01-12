import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Provable.if(in0, in0.not().and(Bool(false)), Provable.if(Bool(false).not().not(), Bool(false), Bool(false).not().not()));
        Provable.log(out0);
        Provable.if(Bool(false), out0, Bool(false)).not().and(Bool(true).and(in0)).or(Provable.if(out0, Provable.if(Bool(false).or(Bool(false)), Bool(false), Provable.if(Bool(false), out0, Bool(false))), Bool(true).or(in0))).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
