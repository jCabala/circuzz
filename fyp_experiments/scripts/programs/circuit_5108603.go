package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_SYPDHNSRYA struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
}

func (circuit *circuit_SYPDHNSRYA) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")
	picus_gnark.CircuitVarIn(circuit.FVar_in3)
	picus_gnark.Label(circuit.FVar_in3, "FVar_in3")

	out0 := api.Add(circuit.FVar_in0, circuit.FVar_in1)
	cons_3 := new(big.Int)
	cons_3.SetString("7512655255124322725536606364613089250377784254604784379998897489406148308192", 10)
	cons_4 := new(big.Int)
	cons_4.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_5 := new(big.Int)
	cons_5.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Mul(api.Sub(out0, circuit.FVar_in1), cons_3), api.Mul(api.Sub(out0, circuit.FVar_in0), cons_4)), cons_5), 1)), 1)
	out1 := api.Add(api.Add(circuit.FVar_in3, circuit.FVar_in1), circuit.FVar_in2)
	cons_10 := new(big.Int)
	cons_10.SetUint64(1)
	cons_11 := new(big.Int)
	cons_11.SetString("18006114786750502508433979801491759776826116965134227670352066489128557401229", 10)
	cons_12 := new(big.Int)
	cons_12.SetString("122546104521938394990388275263578634460147857748009184734711232665900966237", 10)
	cons_13 := new(big.Int)
	cons_13.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Mul(api.Sub(out1, api.Add(circuit.FVar_in1, circuit.FVar_in2)), cons_10), api.Mul(api.Sub(out1, api.Add(circuit.FVar_in3, circuit.FVar_in2)), cons_11)), api.Mul(api.Sub(out1, api.Add(circuit.FVar_in3, circuit.FVar_in1)), cons_12)), cons_13), 1)), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	return nil // no error
}

func main() {
	var circuit circuit_SYPDHNSRYA
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}