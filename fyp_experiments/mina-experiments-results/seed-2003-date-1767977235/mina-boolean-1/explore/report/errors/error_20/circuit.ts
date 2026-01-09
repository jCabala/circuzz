import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = Provable.if(in1, Provable.if(in1, in0, Bool(false)).and(in0).or(Provable.if(Bool(false), in1, Bool(true)).and(Bool(true).or(Bool(false)))), in1);
        Provable.log(out0);
        const out1 = Provable.if(in1.not(), in1.not(), in1);
        Provable.log(out1);
        Bool(false).or(Bool(true).not().not()).not().assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
