import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in0.or(in0.or(Bool(true))).or(Bool(false).and(in0)).and(Bool(true));
        Provable.log(out0);
        const out1 = Bool(false);
        Provable.log(out1);
        out0.or(Bool(false).and(Bool(true)).or(Bool(true).not())).and(Bool(false)).assertTrue();
        Bool(true).not().not().assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
