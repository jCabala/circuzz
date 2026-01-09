import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(1);
        Provable.log(out0);
        const out1 = Field(23308598315890181864876231091577715500650087538455703163664406584391203185189n).neg();
        Provable.log(out1);
        Bool(false).and(Field(10737027894875933773864960588694488439566180340353813305567427424439520026165n).equals(in0.mul(Field(8412713868800408762440864664875180084533101679437973745482655074053907940578n))).not().not()).assertTrue();
        Bool(true).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
