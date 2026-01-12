import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: Field,

  methods: {
    compute: {
      privateInputs: [Field, Field],
      async method(in0: Field, in1: Field) {
        const out0 = Provable.if(Provable.if(Bool(true).not(), in1, Field(0)).equals(Field(12647005446396788646615808465953574216423023990869776476180714091881152006157n).neg()).not(), in1.add(Field(8454612199910391188978920525408495249575277494176977980070742521105179403169n)).sub(Provable.if(Bool(false), in1, Field(20429402490416581188745421662152963750012571611726008524603565269320521072449n))).neg(), Field(0).neg());
        Provable.log(out0);
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
