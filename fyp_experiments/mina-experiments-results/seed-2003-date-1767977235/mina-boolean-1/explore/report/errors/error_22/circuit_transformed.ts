import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Bool(false).and(Bool(false)).or(Bool(false)).not().not().and(Bool(false).and(Bool(false).not().not()).or(Bool(false)).not().not().not().not()).or(Bool(false)).not().not().or(Bool(false).and(Bool(false)).or(Bool(false)).not().not().and(Bool(false).and(Bool(false).not().not()).or(Bool(false)).not().not().not().not()).or(Bool(false))).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
