import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Bool(true).or(Provable.if(Provable.if(in0, in0, Bool(false)), in0, Bool(true)).and(in0));
        Provable.log(out0);
        const out1 = Provable.if(Bool(false), Bool(false).not(), Provable.if(in0, Bool(true), out0).not()).or(Bool(true).not().not().and(Bool(true)));
        Provable.log(out1);
        in0.or(Provable.if(Bool(false), Bool(true), out0).or(Bool(true))).not().assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
