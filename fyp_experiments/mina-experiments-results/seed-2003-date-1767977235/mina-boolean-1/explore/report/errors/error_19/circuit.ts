import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Bool(false).or(Bool(false).or(Provable.if(Bool(false), Bool(true).not(), Bool(false)))).assertTrue();
        Bool(false).not().assertTrue();
        return;
      },
    }
  },
})
export { circuit };
