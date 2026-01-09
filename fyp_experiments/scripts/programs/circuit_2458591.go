package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_X5PCATXU6A struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
}

func (circuit *circuit_X5PCATXU6A) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")

	out0 := circuit.FVar_in1
	cons_2 := new(big.Int)
	cons_2.SetString("14677780467102350174281228862216134290642156386353578365480823130061232648493", 10)
	cons_3 := new(big.Int)
	cons_3.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Mul(out0, cons_2), cons_3), 1)), 1)
	out1 := circuit.FVar_in0
	cons_6 := new(big.Int)
	cons_6.SetString("18818465048338940392346742894971609695937895431665082454407596823408953770530", 10)
	cons_7 := new(big.Int)
	cons_7.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Mul(out1, cons_6), cons_7), 1)
	out2 := api.Add(circuit.FVar_in0, circuit.FVar_in1)
	cons_11 := new(big.Int)
	cons_11.SetString("2390661895504182778195635221186181928801086463795123838715767778727975418505", 10)
	cons_12 := new(big.Int)
	cons_12.SetString("13201463448370606830890021649663122981410610845177999977934314144221126031833", 10)
	cons_13 := new(big.Int)
	cons_13.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Add(api.Mul(api.Sub(out2, circuit.FVar_in1), cons_11), api.Mul(api.Sub(out2, circuit.FVar_in0), cons_12)), cons_13), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	api.Println("out2:", out2)
	return nil // no error
}

func main() {
	var circuit circuit_X5PCATXU6A
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}