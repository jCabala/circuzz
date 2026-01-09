import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(in0.neg().neg().neg().lessThanOrEqual(in1.add(Field(0)).neg().neg().mul(Field(1)).neg()).or(Field(0).add(in1).neg().mul(Field(1)).neg().add(in1.neg()).equals(in1.neg()).not()), in1.neg().neg().neg().neg().neg(), in1);
        Provable.log(out0);
        const out1 = Field(11541031748365296065595417827233074471136017702947732519316807268231145825978n).neg().neg().neg().add(Field(2735876592142379924441569097069040626041058382033905479350550059752977235388n).neg().add(Field(0)).neg()).mul(Field(1)).add(Field(0).add(Field(0)).mul(Field(1)).neg().neg());
        Provable.log(out1);
        Bool(false).assertTrue();
        Bool(false).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
