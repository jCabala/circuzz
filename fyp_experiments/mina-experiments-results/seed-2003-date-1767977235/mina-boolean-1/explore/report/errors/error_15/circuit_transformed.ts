import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Bool(true);
        Provable.log(out0);
        const out1 = Bool(true);
        Provable.log(out1);
        Bool(false).and(Bool(false)).or(Bool(false)).or(Provable.if(Bool(true).not().not(), Provable.if(out0, Bool(true).and(Bool(true)).or(Bool(true).not().not().and(Bool(true))), Bool(false).not().not()).not(), Provable.if(Bool(true), out0.or(out1), in0))).assertTrue();
        Provable.if(in0.or(Bool(true)).not(), Bool(true).not().not(), Provable.if(Bool(false).not().not(), Bool(true), Bool(false).not())).not().or(Provable.if(in0.or(Bool(true)).not(), Bool(true).not().not(), Provable.if(Bool(false).not().not(), Bool(true), Bool(false).not().not().not())).not()).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
