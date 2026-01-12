import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(1).mul(Field(1).mul(Field(21947732948514189181397398525140473922468627202857377988679766844330325197429n).neg().neg().neg()).neg().mul(Field(1)).neg()).mul(Field(1)).add(Field(0).neg().neg());
        Provable.log(out0);
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
