package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_F47HLXWXFC struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
	FVar_in4 frontend.Variable
}

func (circuit *circuit_F47HLXWXFC) Define(api frontend.API) error {
	picus_gnark.CircuitVarIn(circuit.FVar_in0)
	picus_gnark.Label(circuit.FVar_in0, "FVar_in0")
	picus_gnark.CircuitVarIn(circuit.FVar_in1)
	picus_gnark.Label(circuit.FVar_in1, "FVar_in1")
	picus_gnark.CircuitVarIn(circuit.FVar_in2)
	picus_gnark.Label(circuit.FVar_in2, "FVar_in2")
	picus_gnark.CircuitVarIn(circuit.FVar_in3)
	picus_gnark.Label(circuit.FVar_in3, "FVar_in3")
	picus_gnark.CircuitVarIn(circuit.FVar_in4)
	picus_gnark.Label(circuit.FVar_in4, "FVar_in4")

	out0 := api.Add(api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in2), circuit.FVar_in3), circuit.FVar_in0), circuit.FVar_in1)
	cons_6 := new(big.Int)
	cons_6.SetString("5792512133290882545417501108683433039581544467287148128920358046912208173085", 10)
	cons_7 := new(big.Int)
	cons_7.SetString("7293312227833681536478697384717458351260386390776635474467035851821250869122", 10)
	cons_8 := new(big.Int)
	cons_8.SetString("6918314247992100771800849076640741567392460323023646800749975122635401020246", 10)
	cons_9 := new(big.Int)
	cons_9.SetString("1847980502680127095271787694145589392960495801299649708352066037370349970373", 10)
	cons_10 := new(big.Int)
	cons_10.SetString("16527293110152895695042558678982338529762071124573754277881554442142179746790", 10)
	cons_11 := new(big.Int)
	cons_11.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Add(api.Add(api.Mul(api.Sub(out0, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in3), circuit.FVar_in0), circuit.FVar_in1)), cons_6), api.Mul(api.Sub(out0, api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in3), circuit.FVar_in0), circuit.FVar_in1)), cons_7)), api.Mul(api.Sub(out0, api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in2), circuit.FVar_in0), circuit.FVar_in1)), cons_8)), api.Mul(api.Sub(out0, api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in2), circuit.FVar_in3), circuit.FVar_in1)), cons_9)), api.Mul(api.Sub(out0, api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in2), circuit.FVar_in3), circuit.FVar_in0)), cons_10)), cons_11), 1)), 1)
	out1 := api.Add(api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in1), circuit.FVar_in3), circuit.FVar_in0)
	cons_18 := new(big.Int)
	cons_18.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_19 := new(big.Int)
	cons_19.SetString("4558266211164015372972430669946580547100685389806058751216459678957640429778", 10)
	cons_20 := new(big.Int)
	cons_20.SetString("1019361885717096603964686995321096336699266588926446629179103694055190896746", 10)
	cons_21 := new(big.Int)
	cons_21.SetString("15611005021391851392383753385545813529904716981929963606575607648264053360363", 10)
	cons_22 := new(big.Int)
	cons_22.SetString("14380320044806329445427982982290834357033016100152608595023081114408319299540", 10)
	cons_23 := new(big.Int)
	cons_23.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Add(api.Add(api.Mul(api.Sub(out1, api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in1), circuit.FVar_in3), circuit.FVar_in0)), cons_18), api.Mul(api.Sub(out1, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in1), circuit.FVar_in3), circuit.FVar_in0)), cons_19)), api.Mul(api.Sub(out1, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in3), circuit.FVar_in0)), cons_20)), api.Mul(api.Sub(out1, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in1), circuit.FVar_in0)), cons_21)), api.Mul(api.Sub(out1, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in1), circuit.FVar_in3)), cons_22)), cons_23), 1)), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	return nil // no error
}

func main() {
	var circuit circuit_F47HLXWXFC
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}