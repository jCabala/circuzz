import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = in0;
        Provable.log(out0);
        const out1 = Field(1).mul(Field(1)).mul(Field(1).neg().neg()).add(Field(0).mul(Field(1)).add(Field(0).mul(Field(1)).neg().neg().mul(Field(1)).add(Field(3863412435333791297172125783194276018309246167250590571579349600579461981065n).mul(Field(1))).mul(Field(1).mul(Field(1))).neg()).neg().neg().neg()).neg().neg();
        Provable.log(out1);
        Bool(true).not().assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
