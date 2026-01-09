import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in0;
        Provable.log(out0);
        const out1 = in1;
        Provable.log(out1);
        out1.assertTrue();
        Provable.if(Bool(true).not().not(), Bool(true).and(Bool(true).and(Bool(true)).not()), Provable.if(Bool(false), out0, Bool(true).not().and(Bool(true).not())).and(out1).or(Provable.if(Bool(false), out0, Bool(true).and(Bool(true)).not().not().not()).and(Provable.if(Bool(false), out0, Bool(true).not()).and(out1)))).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
