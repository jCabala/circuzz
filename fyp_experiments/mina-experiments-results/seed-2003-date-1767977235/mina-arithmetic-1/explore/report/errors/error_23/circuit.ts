import { Field, Bool, Provable, ZkProgram, Gadgets, Struct } from 'o1js';

class CircuitOutput extends Struct({ out0: Field, out1: Field }) {}

const circuit = ZkProgram({
  name: 'Circuit_pallas',
  publicOutput: CircuitOutput,

  methods: {
    compute: {
      privateInputs: [Field],
      async method(in0: Field) {
        Field(9253691331022963149786517520526886186496529543467421001837997701645588969809n).equals(Field(0)).not().assertTrue();
        const out0 = Field(23388581233241881733439588561390553987929318988718963414752491895613281884554n).div(Field(9253691331022963149786517520526886186496529543467421001837997701645588969809n)).add(in0);
        Provable.log(out0);
        out0.equals(Field(0)).not().assertTrue();
        const out1 = Provable.if(Bool(false).and(Bool(false)).not(), out0.add(Field(8903556654279650709457148459860759019034628173702675846442064519656229066924n).neg()), in0).div(out0);
        Provable.log(out1);
        Bool(false).and(Provable.if(Bool(false), out0, out1).sub(Field(516144393369525645737047763694370905748882575922377131673246459853060806996n)).lessThan(Field(18793052654014145293851612758743523177784737310079833315704221572297374575545n))).assertTrue();
        return { publicOutput: new CircuitOutput({ out0, out1 }) };
      },
    }
  },
})
export { circuit };
