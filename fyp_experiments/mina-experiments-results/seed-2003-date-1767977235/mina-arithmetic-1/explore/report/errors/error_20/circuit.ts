import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(12169383127840886568238472644049448524466020266877907204017896114598749986260n).div(Field(18931480166711123810338114792568760761777567676556956352313348039808666151632n)).neg().neg().add(Field(2486676196320823906306716571448553614499608281209374721254158092156094913345n).mul(Provable.if(Bool(true), in0.neg(), in0.add(Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n)))));
        Provable.log(out0);
        Bool(false).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
