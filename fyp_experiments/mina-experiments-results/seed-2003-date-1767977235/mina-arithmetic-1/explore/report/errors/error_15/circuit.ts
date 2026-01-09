import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(in0.neg().lessThanOrEqual(in1.neg()).or(in1.sub(in1).equals(in1.neg()).not()), in1.neg(), in1);
        Provable.log(out0);
        const out1 = Field(11541031748365296065595417827233074471136017702947732519316807268231145825978n).neg().sub(Field(2735876592142379924441569097069040626041058382033905479350550059752977235388n).neg()).neg().neg();
        Provable.log(out1);
        Bool(false).assertTrue();
        Bool(false).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
