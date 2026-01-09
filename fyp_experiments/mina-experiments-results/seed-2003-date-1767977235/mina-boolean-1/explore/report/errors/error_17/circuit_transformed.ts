import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = Bool(true).and(in0.not().not().or(Bool(true).or(in0).or(Bool(false).and(in0)).not().not()));
        Provable.log(out0);
        const out1 = Bool(false);
        Provable.log(out1);
        Bool(false).and(out0.or(Bool(false).and(Bool(true)).or(Bool(true).not())).and(Bool(false).and(Bool(false)))).and(Bool(true).not().not().not().or(Bool(false).and(Bool(true)).and(Bool(false)).and(Bool(true)).or(out0))).assertTrue();
        Bool(true).and(Bool(true).not().not()).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
