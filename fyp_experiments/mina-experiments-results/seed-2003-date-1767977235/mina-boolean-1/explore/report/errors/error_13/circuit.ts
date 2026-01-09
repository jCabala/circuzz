import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Provable.if(Bool(true), Bool(true), in0.or(Provable.if(in0, Bool(false), in0).or(Bool(false).not())));
        Provable.log(out0);
        const out1 = in0;
        Provable.log(out1);
        in0.not().assertTrue();
        Provable.if(Bool(false), Bool(true), Provable.if(out1.and(Bool(false)).or(Bool(false)), in0, Bool(false))).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
