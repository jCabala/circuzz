package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_G0FA5XCFV0 struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
}

func (circuit *circuit_G0FA5XCFV0) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")

	out0 := circuit.FVar_in1
	cons_2 := new(big.Int)
	cons_2.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_3 := new(big.Int)
	cons_3.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Mul(out0, cons_2), cons_3), 1)
	api.Println("out0:", out0)
	return nil // no error
}

func main() {
	var circuit circuit_G0FA5XCFV0
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}