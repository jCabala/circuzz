import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(Field(0).add(Provable.if(Bool(true).not(), in1, Field(0))).equals(Field(12647005446396788646615808465953574216423023990869776476180714091881152006157n).neg()).not(), Provable.if(Bool(false), in1, Field(20429402490416581188745421662152963750012571611726008524603565269320521072449n)).neg().neg().neg().add(Field(0)).neg().neg().neg().neg().add(Field(1).mul(Field(8454612199910391188978920525408495249575277494176977980070742521105179403169n)).mul(Field(1).neg().neg())).add(in1).neg(), Field(1).mul(Field(0).neg())).mul(Field(1).neg().neg().add(Field(0))).mul(Field(1));
        Provable.log(out0);
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
