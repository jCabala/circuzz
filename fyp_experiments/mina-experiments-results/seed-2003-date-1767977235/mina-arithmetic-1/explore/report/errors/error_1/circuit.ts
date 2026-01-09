import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        Bool(false).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
