import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Bool(false).assertTrue();
        Bool(true).not().or(Bool(true).not()).or(Bool(true).not()).not().not().and(Bool(true).not().or(Bool(true).not()).or(Bool(true).not()).not().not()).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
