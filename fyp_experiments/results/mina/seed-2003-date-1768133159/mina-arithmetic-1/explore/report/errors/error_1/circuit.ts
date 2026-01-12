import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(21947732948514189181397398525140473922468627202857377988679766844330325197429n).neg();
        Provable.log(out0);
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
