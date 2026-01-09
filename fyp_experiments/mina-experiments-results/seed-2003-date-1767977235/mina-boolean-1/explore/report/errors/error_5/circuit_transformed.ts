import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in1.or(Bool(true).not().or(in1.not()).and(in1.and(Bool(true)).not()).and(Bool(true).and(in1).or(Bool(true).and(in1)).and(Bool(true).and(in1).or(Bool(true).and(in1))).not())).or(in1.or(Bool(true).and(in1).not().and(Bool(true).not().or(in1.not())).and(Bool(true).and(in1).not()))).or(Bool(true).not()).or(in0).not();
        Provable.log(out0);
        const out1 = in0.not();
        Provable.log(out1);
        Bool(true).not().assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
