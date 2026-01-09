import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        const out0 = Field(1).neg();
        Provable.log(out0);
        out0.equals(Field(0)).not().assertTrue();
        const out1 = Provable.if(Bool(true), Provable.if(Bool(false), in0, Field(8201493959609560990588848223616104438114550909366340561144447856755019698788n)), in0.neg()).div(out0).neg();
        Provable.log(out1);
        out0.lessThan(out0).assertTrue();
        Bool(true).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
