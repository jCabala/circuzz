import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Provable.if(Bool(true), Bool(true), Bool(false).not().or(in0.or(Provable.if(in0, Bool(false), in0))).and(Provable.if(in0, Bool(false), in0).or(in0.or(Provable.if(in0, Bool(false), in0)).or(in0)).or(Bool(false).not())));
        Provable.log(out0);
        const out1 = in0;
        Provable.log(out1);
        in0.not().assertTrue();
        Provable.if(Bool(false), Bool(true).not().not(), Provable.if(Bool(false).not().not().and(out1).or(Bool(false).and(out1)).or(Bool(false)), in0, Bool(false))).not().not().or(Provable.if(Bool(false), Bool(true), Provable.if(Bool(false).and(out1).or(Bool(false)), in0, Bool(false)).and(Provable.if(out1.and(Bool(false)).or(Bool(false)), in0, Bool(false))))).and(Provable.if(Bool(false), Bool(true), Provable.if(Bool(false).or(out1.and(Bool(false)).or(out1.and(Bool(false)))), in0, Bool(false))).not().not().or(Provable.if(Bool(false), Bool(true), Provable.if(out1.and(Bool(false)).or(Bool(false)), in0, Bool(false))))).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
