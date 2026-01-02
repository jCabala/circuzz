package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_DEYTKGK4B6 struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
}

func (circuit *circuit_DEYTKGK4B6) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")

	out0 := circuit.FVar_in1
	cons_2 := new(big.Int)
	cons_2.SetUint64(1)
	cons_3 := new(big.Int)
	cons_3.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Mul(out0, cons_2), cons_3), 1)), 1)
	api.Println("out0:", out0)
	return nil // no error
}

func main() {
	var circuit circuit_DEYTKGK4B6
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}