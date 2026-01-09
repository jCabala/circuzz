import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(Bool(true).or(Bool(false)).not().and(Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n).add(Field(1)).equals(in1)), Field(0).mul(Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n)).div(Field(6590889802414833538789757038039702222902382127196940221284410658605059303972n)), in0);
        Provable.log(out0);
        const out1 = Field(1);
        Provable.log(out1);
        in1.equals(Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n)).not().assertTrue();
        Bool(true).not().or(Bool(false)).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
