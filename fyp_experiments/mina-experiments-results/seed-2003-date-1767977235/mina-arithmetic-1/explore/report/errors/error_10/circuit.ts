import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = in0;
        Provable.log(out0);
        Bool(false).not().assertTrue();
        Bool(true).not().assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
