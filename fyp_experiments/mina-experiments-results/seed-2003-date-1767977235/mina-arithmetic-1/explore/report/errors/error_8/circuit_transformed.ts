import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        const out0 = Provable.if(Bool(false).not().or(Bool(false).and(Bool(false))), in0, Field(28461168768760370220138085473466822053091293307034135425164606655956805139973n).mul(in0).add(Field(0)).neg()).neg();
        Provable.log(out0);
        const out1 = Field(5507111550643448407825635441032097677384094300111985185050561050172088525024n).neg();
        Provable.log(out1);
        Bool(false).assertTrue();
        Bool(true).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
