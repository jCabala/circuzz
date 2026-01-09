import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(Bool(false).not().not().not(), Field(0).mul(Field(1).mul(Field(1))), Field(19598765152304836338090110442789765813876847300459818449529517315255432427817n)).add(Field(0));
        Provable.log(out0);
        Bool(true).not().not().assertTrue();
        Field(21432492560216254034467066011698416895446132495641626147041670588766777221634n).lessThan(Provable.if(Bool(true), Field(5109171117691318088310251515892099093519670122676795950447572428827251619572n), Field(0).add(in0)).add(Field(0))).or(Bool(true)).and(Bool(true).and(Bool(false)).not().not()).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
