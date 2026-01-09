import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Provable.if(Provable.if(in0, in0.not().not().not(), in0).not().or(Provable.if(in0, in0.not(), in0).not()).or(Provable.if(in0, in0.not().not().not(), in0).or(Provable.if(in0, in0.not().and(in0.not()).not().or(in0.not().not()).not(), in0)).not()).not().not(), Bool(false), Bool(false)).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
