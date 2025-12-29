package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_P1E8NVS60M struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
}

func (circuit *circuit_P1E8NVS60M) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")

	out0 := api.Add(circuit.FVar_in0, circuit.FVar_in1)
	cons_3 := new(big.Int)
	cons_3.SetString("21571118644954027015100530998942991116460381592865574977364364217970547245087", 10)
	cons_4 := new(big.Int)
	cons_4.SetString("5759609138561993239229891963550024121252984060264100684683910217995538896664", 10)
	cons_5 := new(big.Int)
	cons_5.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Add(api.Mul(api.Sub(out0, circuit.FVar_in1), cons_3), api.Mul(api.Sub(out0, circuit.FVar_in0), cons_4)), cons_5), 1)
	api.Println("out0:", out0)
	return nil // no error
}

func main() {
	var circuit circuit_P1E8NVS60M
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}