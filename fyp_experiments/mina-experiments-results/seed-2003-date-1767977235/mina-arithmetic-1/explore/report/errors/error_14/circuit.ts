import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        Bool(false).not().assertTrue();
        in0.equals(Field(0)).not().assertTrue();
        Bool(false).and(Provable.if(Bool(true).not(), in1, in1).lessThan(Provable.if(Bool(false), in1.div(in0), in0))).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
