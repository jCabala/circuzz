import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Field(0).neg().add(Field(0)).neg().add(Field(24498806783426925801702951377145752247523021492574466755696730342843282191417n).neg().add(Field(7254602166180766177030162657044915273783271940076100760223573622349505281042n))).neg();
        Provable.log(out0);
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
