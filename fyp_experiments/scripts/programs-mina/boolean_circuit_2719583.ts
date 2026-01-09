import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Bool, out1: Bool }) {}

const circuit = ZkProgram({
  name: 'circuit_7AH8PA6HW0',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Bool, Bool, Bool, Bool],
      async method(in0: Bool, in1: Bool, in2: Bool, in3: Bool) {
        const out0 = Provable.if(in2.not(), Bool(true).and(Bool(true)), in2.not());
        Provable.log(out0);
        const out1 = in2.equals(Bool(true)).not().equals(in3.equals(out0)).not();
        Provable.log(out1);
        Bool(false).assertTrue();
        return new CircuitOutput({ out0, out1 });
      },
    }
  },
})
export { circuit };
