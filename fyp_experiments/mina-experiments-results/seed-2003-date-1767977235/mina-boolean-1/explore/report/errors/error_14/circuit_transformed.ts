import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in1;
        Provable.log(out0);
        const out1 = Bool(false).and(Bool(false).not().not().and(Bool(false).not().not().not().not()).or(Bool(false))).not().not().not().not();
        Provable.log(out1);
        out1.assertTrue();
        out0.assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
