package main

import (
	"github.com/Veridise/picus_gnark"
	"github.com/consensys/gnark-crypto/ecc"
	"github.com/consensys/gnark/frontend"
)

type circuit_HMIXFIQ0Y2 struct {
	FVar_in0 frontend.Variable
	FVar_in1 frontend.Variable
	FVar_in2 frontend.Variable
	FVar_in3 frontend.Variable
	FVar_in4 frontend.Variable
}

func (circuit *circuit_HMIXFIQ0Y2) Define(api frontend.API) error {
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

	out0 := api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in1)
	cons_4 := new(big.Int)
	cons_4.SetString("18086051190491136877645066317778147163515491450313817816335988782708813483972", 10)
	cons_5 := new(big.Int)
	cons_5.SetString("11601683925262695138946621424520422530848729111741579633044455292233652271603", 10)
	cons_6 := new(big.Int)
	cons_6.SetString("17392497354542220980587139904998776905256867300495767095068344789300539013277", 10)
	cons_7 := new(big.Int)
	cons_7.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Add(api.Add(api.Mul(api.Sub(out0, api.Add(circuit.FVar_in4, circuit.FVar_in1)), cons_4), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in2, circuit.FVar_in1)), cons_5)), api.Mul(api.Sub(out0, api.Add(circuit.FVar_in2, circuit.FVar_in4)), cons_6)), cons_7), 1)
	out1 := api.Add(api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in0), circuit.FVar_in3), circuit.FVar_in1)
	cons_13 := new(big.Int)
	cons_13.SetString("14423869148697148787097153128248318704612737527085202490222478193401703287274", 10)
	cons_14 := new(big.Int)
	cons_14.SetString("2070833423321301670061210320515509555939654842594342390797748257068907866757", 10)
	cons_15 := new(big.Int)
	cons_15.SetString("2377734266413122886571420782955819400659971224544157549730918279046384920334", 10)
	cons_16 := new(big.Int)
	cons_16.SetString("11803206095033299075655073522222084673542367102240534062296551170021575685408", 10)
	cons_17 := new(big.Int)
	cons_17.SetUint64(0)
	api.AssertIsEqual(cmp.IsLess(api, api.Add(api.Add(api.Add(api.Mul(api.Sub(out1, api.Add(api.Add(circuit.FVar_in0, circuit.FVar_in3), circuit.FVar_in1)), cons_13), api.Mul(api.Sub(out1, api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in3), circuit.FVar_in1)), cons_14)), api.Mul(api.Sub(out1, api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in0), circuit.FVar_in1)), cons_15)), api.Mul(api.Sub(out1, api.Add(api.Add(circuit.FVar_in4, circuit.FVar_in0), circuit.FVar_in3)), cons_16)), cons_17), 1)
	out2 := api.Add(api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in1), circuit.FVar_in4), circuit.FVar_in3), circuit.FVar_in0)
	cons_24 := new(big.Int)
	cons_24.SetString("10401302061204543176724262041675794469536665153687142106688382608704421711322", 10)
	cons_25 := new(big.Int)
	cons_25.SetString("18243726036976419938671062828139161381161264411904559206073441752719050807978", 10)
	cons_26 := new(big.Int)
	cons_26.SetString("20674835155932595818205874004589029988666542997752785115877393604845659633763", 10)
	cons_27 := new(big.Int)
	cons_27.SetString("7584151475367491154064586383287944304871276098995406850471125053153665618777", 10)
	cons_28 := new(big.Int)
	cons_28.SetString("21888242871839275222246405745257275088548364400416034343698204186575808495616", 10)
	cons_29 := new(big.Int)
	cons_29.SetUint64(0)
	api.AssertIsEqual(api.IsZero(api.Cmp(api.Cmp(api.Add(api.Add(api.Add(api.Add(api.Mul(api.Sub(out2, api.Add(api.Add(api.Add(circuit.FVar_in1, circuit.FVar_in4), circuit.FVar_in3), circuit.FVar_in0)), cons_24), api.Mul(api.Sub(out2, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in4), circuit.FVar_in3), circuit.FVar_in0)), cons_25)), api.Mul(api.Sub(out2, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in1), circuit.FVar_in3), circuit.FVar_in0)), cons_26)), api.Mul(api.Sub(out2, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in1), circuit.FVar_in4), circuit.FVar_in0)), cons_27)), api.Mul(api.Sub(out2, api.Add(api.Add(api.Add(circuit.FVar_in2, circuit.FVar_in1), circuit.FVar_in4), circuit.FVar_in3)), cons_28)), cons_29), 1)), 1)
	api.Println("out0:", out0)
	api.Println("out1:", out1)
	api.Println("out2:", out2)
	return nil // no error
}

func main() {
	var circuit circuit_HMIXFIQ0Y2
	picus_gnark.CompilePicus("circuit", &circuit, ecc.BN254.ScalarField())
}