import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        Bool(true).or(Bool(true)).and(Bool(false).or(Bool(true))).not().and(Bool(false).not()).assertTrue();
        Bool(false).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
