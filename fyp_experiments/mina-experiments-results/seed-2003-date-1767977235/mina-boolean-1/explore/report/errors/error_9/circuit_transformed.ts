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
        const out1 = in0;
        Provable.log(out1);
        Provable.if(Provable.if(Bool(false).or(Bool(false)), out1.not(), Provable.if(Bool(false).or(Bool(false)).or(Bool(false)), in0.or(Bool(true)), in0.not().not().not().or(in0.not().not().or(in0.not().not()).not().and(in0.not().not().not())))), Bool(false), Provable.if(Bool(false).not().not(), in0.and(in0).not(), out0.or(Bool(false).and(out0))).or(Provable.if(Bool(false), in0.not(), out0.or(Bool(false).and(out0))))).and(Provable.if(Provable.if(Bool(false), out1.not(), Provable.if(Bool(false), in0.or(Bool(true)), in0.or(in0).and(in0.not().not()).or(in0.or(in0).and(in0.not().not())).not())), Bool(false), Provable.if(Bool(false).not().not().or(Bool(false).not().not()), in0.not(), out0.or(Bool(false).and(out0))))).assertTrue();
        Provable.if(Bool(false).not(), Bool(false), in0).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
