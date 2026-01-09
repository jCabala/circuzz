import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Bool(false).or(Provable.if(Bool(false), Bool(true).not(), Bool(false)).or(Provable.if(Bool(false).and(Bool(false)), Bool(true).not(), Bool(false)).not().not())).or(Bool(false).not().and(Provable.if(Bool(false), Bool(true).not().not().and(Bool(true)).not(), Bool(false)).or(Provable.if(Bool(false).and(Bool(false)), Bool(true).not(), Bool(false).and(Bool(false))).or(Bool(false).or(Provable.if(Bool(false), Bool(true).not(), Bool(false)).or(Provable.if(Bool(false), Bool(true).not(), Bool(false).or(Bool(false)))))).or(Provable.if(Bool(false), Bool(true).not().or(Bool(true).not()), Bool(false)).or(Provable.if(Bool(false), Bool(true).not(), Bool(false))))).not()).not()).assertTrue();
        Bool(false).or(Bool(false)).not().or(Bool(false).or(Bool(false)).not()).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
