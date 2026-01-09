import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        Bool(true).not().not().not().assertTrue();
        Bool(true).and(Field(15257039408938269223362842442345922124957191741755686821124915261627558222341n).greaterThanOrEqual(Field(0).mul(Provable.if(Bool(true).and(Bool(false)), in0, Provable.if(Bool(true), Field(1).neg().neg().neg().neg().add(Field(0).neg().neg()), Field(4510446184910569453043112517594998709856741351436216650311312347650887032239n).mul(Field(1)))).mul(Field(1))).add(Field(1).mul(Provable.if(Bool(true).and(Bool(false)), in0, Provable.if(Bool(true), Field(1).neg().neg().add(Field(0)).add(Field(0).add(Field(0)).neg().neg()), Field(4510446184910569453043112517594998709856741351436216650311312347650887032239n).mul(Field(1)))).mul(Field(1)))).add(Field(0)))).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
