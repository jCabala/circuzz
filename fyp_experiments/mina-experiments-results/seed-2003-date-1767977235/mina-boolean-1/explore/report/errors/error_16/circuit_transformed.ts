import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool, Bool],
      async method(in0: Bool, in1: Bool) {
        const out0 = in1;
        Provable.log(out0);
        Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)).or(Bool(false).or(Bool(false))).or(Bool(false)), in1.and(Bool(true).and(out0)))).and(Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)), out0.and(Bool(true).or(Bool(true))).not().or(in1.not()).not())).or(Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)).not().not().or(Bool(false).or(Bool(false)).not().not()).not().not().or(Bool(false)), out0.and(Bool(true).not().not().or(Bool(true)).and(in1))).not().not()))).or(Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)).or(Bool(false)).or(Bool(false)), in1.and(Bool(true).not().not().not().not().and(out0)))).and(Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)), out0.and(Bool(true).or(Bool(true))).and(in1))).or(Provable.if(Bool(true), Bool(false), Provable.if(in1, Bool(false).or(Bool(false)).or(Bool(false)), out0.and(Bool(true).not().not().or(Bool(true)).and(in1))).not().not())))).assertTrue();
        Bool(true).or(Bool(true).not().not()).or(Bool(true)).or(Bool(true)).not().not().not().assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
