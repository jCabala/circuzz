import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        const out0 = Field(0).add(in0).neg().neg().add(Field(0).neg().neg().neg().neg().neg().neg());
        Provable.log(out0);
        Bool(false).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
