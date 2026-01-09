import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(0).add(Field(0).mul(Field(1)).add(in0.mul(Field(1)).neg())).neg().add(Field(0).mul(Field(1).add(Field(0).mul(Field(1)))).neg().neg());
        Provable.log(out0);
        Bool(false).not().assertTrue();
        Bool(true).not().assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
