import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Provable.if(in0, in0, Bool(true)).and(Bool(false)).not().not();
        Provable.log(out0);
        const out1 = Bool(false);
        Provable.log(out1);
        out1.or(out0.or(in0.not())).not().assertTrue();
        Provable.if(Bool(false).and(Bool(true)).or(in0.or(Bool(true))).not(), out1, out1).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
