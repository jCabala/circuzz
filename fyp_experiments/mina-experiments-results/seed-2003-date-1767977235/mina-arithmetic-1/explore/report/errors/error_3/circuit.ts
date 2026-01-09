import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        Bool(true).not().assertTrue();
        return;
      },
    }
  },
})
export { circuit };
