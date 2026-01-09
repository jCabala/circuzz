import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        Bool(true).or(in1.lessThanOrEqual(Field(23698382004286117557643057317692590867908767386209617644631877304364128745743n).neg().add(Field(0)).neg().mul(Field(1))).or(Bool(true)).not()).assertTrue();
        Field(1).neg().neg().lessThanOrEqual(Provable.if(Bool(false), Field(3643327320103315312194559345798956549545141026931099714141624891649999984250n), Field(6789023389286347483538284112081493827150092489355070364659275845777765289132n).add(Field(1).mul(Field(0))).add(Field(0))).neg().mul(Field(1).add(Field(0)))).not().assertTrue();
        return;
      },
    }
  },
})
export { circuit };
