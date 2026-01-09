import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        const out0 = Provable.if(Bool(true).not().and(Bool(false).and(Bool(true))), Provable.if(in0.greaterThanOrEqual(in0), Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n).mul(Field(0)), in0), in0.neg().add(Field(1160929379376470533249377526046682881163355487677030393175285907851326558664n).sub(in0))).neg();
        Provable.log(out0);
        Bool(true).and(Bool(false)).not().not().and(Bool(true)).assertTrue();
        out0.neg().greaterThan(out0).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
