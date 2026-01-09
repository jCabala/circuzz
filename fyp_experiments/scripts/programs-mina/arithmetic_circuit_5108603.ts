import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'circuit_ASYPDHNSRY',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field, Field, Field],
      async method(in0: Field, in1: Field, in2: Field, in3: Field) {
        const out0 = Field(4533938635144197851876817422299120374394316705046794679518519301691344186901n);
        Provable.log(out0);
        const out1 = out0.mul(in2);
        Provable.log(out1);
        Field(21888242871839275222246405745257275088548364400416034343698204186575808495617n).equals(Field(7231283731095352757878489710015738548211352238928037529722537445646162224695n)).not().assertTrue();
        return new CircuitOutput({ out0, out1 });
      },
    }
  },
})
export { circuit };
