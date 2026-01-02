import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool, out2: Bool }) {}

const circuit = ZkProgram({
  name: 'circuit_74BJRN3X5P',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = Provable.if(Bool(true), in0, in0).not();
        Provable.log(out0);
        const out1 = Bool(true);
        Provable.log(out1);
        const out2 = Provable.if(Bool(false), Bool(true), Bool(true)).equals(in1);
        Provable.log(out2);
        Bool(false).not().assertTrue();
        return new CircuitOutput({ out0, out1, out2 });
      },
    }
  },
})
export { circuit };
