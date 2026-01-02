package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_1TFEHBMB4E struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
}

func (circuit *circuit_1TFEHBMB4E) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")
	picus_gnark.CircuitVarIn(circuit.FVar_in3)
	picus_gnark.Label(circuit.FVar_in3, "FVar_in3")

	out0 := api.Add(api.Add(circuit.FVar_in1, circuit.FVar_in3), circuit.FVar_in0)
	cons_4 := new(big.Int)
	cons_4.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_5 := new(big.Int)
	cons_5.SetUint64(1)
	cons_6 := new(big.Int)
	cons_6.SetString("19836335445869407697839606750317752026537467959115018733165236009989994544150", 10)
	cons_7 := new(big.Int)
	cons_7.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Mul(api.Sub(out0, api.Add(circuit.FVar_in3, circuit.FVar_in0)), cons_4), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in1, circuit.FVar_in0)), cons_5)), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in1, circuit.FVar_in3)), cons_6)), cons_7), 1)), 1)
	out1 := api.Add(api.Add(circuit.FVar_in3, circuit.FVar_in1), circuit.FVar_in0)
	cons_12 := new(big.Int)
	cons_12.SetString("17157183666151086547122977390345470201300820833285191504114659764635996245716", 10)
	cons_13 := new(big.Int)
	cons_13.SetString("4368260560054521519242651439353245302004939927104399331355068817741404745095", 10)
	cons_14 := new(big.Int)
	cons_14.SetString("20476821946802959754363029322315874560658247538808392786535251004410807202383", 10)
	cons_15 := new(big.Int)
	cons_15.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Add(api.Add(api.Mul(api.Sub(out1, api.Add(circuit.FVar_in1, circuit.FVar_in0)), cons_12), api.Mul(api.Sub(out1, api.Add(circuit.FVar_in3, circuit.FVar_in0)), cons_13)), api.Mul(api.Sub(out1, api.Add(circuit.FVar_in3, circuit.FVar_in1)), cons_14)), cons_15), 1)
	out2 := api.Add(api.Add(circuit.FVar_in0, circuit.FVar_in3), circuit.FVar_in2)
	cons_20 := new(big.Int)
	cons_20.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_21 := new(big.Int)
	cons_21.SetUint64(1)
	cons_22 := new(big.Int)
	cons_22.SetString("261416602435972119896434299360308362323912527345849868846819033137297859382", 10)
	cons_23 := new(big.Int)
	cons_23.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Mul(api.Sub(out2, api.Add(circuit.FVar_in3, circuit.FVar_in2)), cons_20), api.Mul(api.Sub(out2, api.Add(circuit.FVar_in0, circuit.FVar_in2)), cons_21)), api.Mul(api.Sub(out2, api.Add(circuit.FVar_in0, circuit.FVar_in3)), cons_22)), cons_23), 1)), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	api.Println("out2:", out2)
	return nil // no error
}

func main() {
	var circuit circuit_1TFEHBMB4E
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}