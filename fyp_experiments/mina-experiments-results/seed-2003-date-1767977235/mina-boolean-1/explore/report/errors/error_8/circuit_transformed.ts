import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        Bool(false).or(Bool(false)).or(Bool(false).or(Bool(false))).not().not().assertTrue();
        return;
      },
    }
  },
})
export { circuit };
