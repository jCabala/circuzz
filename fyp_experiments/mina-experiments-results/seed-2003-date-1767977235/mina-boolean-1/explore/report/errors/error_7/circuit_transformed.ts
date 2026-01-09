import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas_eq',
  publicOutput: Bool,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        const out0 = Bool(true).and(Bool(true).and(Bool(true)).and(Bool(true))).and(Bool(true)).and(Bool(true));
        Provable.log(out0);
        Bool(true).assertTrue();
        Bool(false).assertTrue();
        return { publicOutput: out0 };
      },
    }
  },
})
export { circuit };
