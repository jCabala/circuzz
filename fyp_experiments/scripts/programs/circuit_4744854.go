package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_SDNH3Q40HB struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
}

func (circuit *circuit_SDNH3Q40HB) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")
	picus_gnark.CircuitVarIn(circuit.FVar_in3)
	picus_gnark.Label(circuit.FVar_in3, "FVar_in3")

	out0 := api.Add(api.Add(circuit.FVar_in1, circuit.FVar_in2), circuit.FVar_in3)
	cons_4 := new(big.Int)
	cons_4.SetString("7205356840343402014157873628721959233418306726179090992835015498243751693", 10)
	cons_5 := new(big.Int)
	cons_5.SetString("809302130532734279787223068601784916637895591726676280408635776640160352112", 10)
	cons_6 := new(big.Int)
	cons_6.SetString("19418319030590636592649111924143122633809196933458565820827341675359572065515", 10)
	cons_7 := new(big.Int)
	cons_7.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Mul(api.Sub(out0, api.Add(circuit.FVar_in2, circuit.FVar_in3)), cons_4), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in1, circuit.FVar_in3)), cons_5)), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in1, circuit.FVar_in2)), cons_6)), cons_7), 1)), 1)
	out1 := circuit.FVar_in1
	cons_10 := new(big.Int)
	cons_10.SetString("2035396400099161614846027649100223500594019351120072155717322106837324129870", 10)
	cons_11 := new(big.Int)
	cons_11.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Mul(out1, cons_10), cons_11), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	return nil // no error
}

func main() {
	var circuit circuit_SDNH3Q40HB
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}