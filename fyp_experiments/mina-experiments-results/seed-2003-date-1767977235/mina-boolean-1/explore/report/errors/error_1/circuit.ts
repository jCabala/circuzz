import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: undefined,

  methods: {
    compute: {
      privateInputs: [Bool],
      async method(in0: Bool) {
        Provable.if(Provable.if(in0, in0.not(), in0).not(), Bool(false), Bool(false)).assertTrue();
        return;
      },
    }
  },
})
export { circuit };
