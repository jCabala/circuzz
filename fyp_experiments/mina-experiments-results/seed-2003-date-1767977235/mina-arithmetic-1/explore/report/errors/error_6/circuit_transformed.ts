import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        const out0 = Field(17243609283139688213862698432190853536285445321989706604072960161999453135050n).add(Field(0)).neg().neg();
        Provable.log(out0);
        Bool(true).assertTrue();
        Field(1).mul(Field(1).mul(Field(0))).neg().neg().neg().neg().greaterThan(Field(21058598477835560449975430283221928478857030131349599011003500338757161787799n).neg().add(Field(28948022309329048855892746252171976963363056481941560715954676764349967630336n).neg().neg())).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
