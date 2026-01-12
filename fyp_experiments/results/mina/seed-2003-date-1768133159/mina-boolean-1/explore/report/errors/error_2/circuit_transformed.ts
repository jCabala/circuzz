import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Provable.if(in0, in0.not().and(in0.not().and(Bool(false))), Provable.if(Bool(false), Bool(false), Bool(false)));
        Provable.log(out0);
        Provable.if(out0, Provable.if(Bool(false), Bool(false).not().not(), Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false), out0, Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false).or(Bool(false)), out0, Bool(false))))), Bool(true).or(in0)).or(Provable.if(out0, Provable.if(Bool(false), Bool(false).not().not(), Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false), out0, Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false).or(Bool(false).or(Bool(false))), out0, Bool(false)))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false), out0, Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false).or(Bool(false).or(Bool(false))), out0, Bool(false)))))), Bool(true).or(in0)).or(Provable.if(out0, Provable.if(Bool(false), Bool(false).not().not(), Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false), out0, Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false).or(Bool(false).or(Bool(false))), out0, Bool(false)))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false), out0, Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)).or(Provable.if(Bool(false).or(Bool(false)), out0, Bool(false)))))), Bool(true).or(in0)))).or(in0.and(Bool(true)).and(Bool(true)).and(Provable.if(Bool(false), out0, Bool(false)).not().or(Provable.if(Bool(false), out0, Bool(false).and(Bool(false))).not()))).or(Bool(true).and(in0.and(Provable.if(Bool(false), out0, Bool(false)).not().not().and(Provable.if(Bool(false), out0, Bool(false).or(Bool(false)))).or(Provable.if(Bool(false), out0, Bool(false).or(Bool(false))).and(Provable.if(Bool(false), out0, Bool(false)))).not()).or(in0.and(Provable.if(Bool(false), out0, Bool(false)).not().and(Provable.if(Bool(false), out0, Bool(false)).not())))).and(Bool(true).and(in0.and(Provable.if(Bool(false), out0, Bool(false)).and(Provable.if(Bool(false), out0, Bool(false).or(Bool(false)))).not().and(Provable.if(Bool(false), out0, Bool(false).or(Bool(false))).and(Provable.if(Bool(false), out0, Bool(false))).not())).or(in0.and(Provable.if(Bool(false), out0, Bool(false)).not().and(Provable.if(Bool(false), out0, Bool(false)).not())))))).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
