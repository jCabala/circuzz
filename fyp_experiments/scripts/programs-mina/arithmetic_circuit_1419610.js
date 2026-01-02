import { Field, Bool, Provable, ZkProgram } from 'o1js';
const circuit = ZkProgram({
    name: 'circuit_0ZGPJR0JCX',
    publicOutput: Field,
    methods: {
        compute: {
            privateInputs: [Field, Field],
            async method(in0, in1) {
                const out0 = Field(15942136664796946224429294923492700211206925428015226280593525965740936230708n).add(in1).neg();
                Provable.log(out0);
                Field(6123820121165653082154130192830459850306698777692923016039377341339394853633n).equals(out0).not().assertTrue();
                Bool(true).not().not().assertTrue();
                Bool(false).not().not().assertTrue();
                return out0;
            },
        }
    },
});
export { circuit };
