package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_E5BF6A1EU7 struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
}

func (circuit *circuit_E5BF6A1EU7) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")
	picus_gnark.CircuitVarIn(circuit.FVar_in3)
	picus_gnark.Label(circuit.FVar_in3, "FVar_in3")

	out0 := circuit.FVar_in1
	cons_2 := new(big.Int)
	cons_2.SetString("9524440343497449610392921471730508295452609615790250400202381363754925353462", 10)
	cons_3 := new(big.Int)
	cons_3.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Mul(out0, cons_2), cons_3), 1)), 1)
	out1 := api.Add(circuit.FVar_in3, circuit.FVar_in2)
	cons_7 := new(big.Int)
	cons_7.SetString("12705457941769579939708955464494162172743339280572153931116482726437997252071", 10)
	cons_8 := new(big.Int)
	cons_8.SetString("1964508855259289195706497229996022787137421593816158860321989087451336474013", 10)
	cons_9 := new(big.Int)
	cons_9.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Mul(api.Sub(out1, circuit.FVar_in2), cons_7), api.Mul(api.Sub(out1, circuit.FVar_in3), cons_8)), cons_9), 1)), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	return nil // no error
}

func main() {
	var circuit circuit_E5BF6A1EU7
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}