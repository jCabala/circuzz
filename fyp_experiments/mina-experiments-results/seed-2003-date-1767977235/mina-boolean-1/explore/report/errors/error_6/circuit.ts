import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in0.not().not();
        Provable.log(out0);
        const out1 = in1;
        Provable.log(out1);
        out1.assertTrue();
        Provable.if(Bool(true), Bool(true).not().and(Bool(true)), out1.and(Provable.if(Bool(false), out0, Bool(true).not()))).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
