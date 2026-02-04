#!/usr/bin/env bash
set -euo pipefail

OUT_DIR="${OUT_DIR:-origin}"
CIRCOM="${CIRCOM:-circom}"
SNARKJS="${SNARKJS:-$(command -v snarkjs || true)}"
NODE="${NODE:-$(command -v node || true)}"
PRIME="${PRIME:-bn128}"
OPT="${OPT:-O2}"
PTAU="${PTAU:-./ppot_0080_17.ptau}"
TRY_FULLPROVE="${TRY_FULLPROVE:-1}"   # 1 = attempt groth16 fullprove if prove fails

CIRCUIT_NAME="circuit_bad" # Change to circuit_good for other test

CIRCUIT_SRC="$CIRCUIT_NAME.circom"
INPUT_JSON="input.json"

R1CS="$OUT_DIR/$CIRCUIT_NAME.r1cs"
WASM="$OUT_DIR/${CIRCUIT_NAME}_js/$CIRCUIT_NAME.wasm"
GEN_WTN="$OUT_DIR/${CIRCUIT_NAME}_js/generate_witness.js"
WTNS="$OUT_DIR/witness.wtns"

ZKEY="$OUT_DIR/groth16_final.zkey"
PROOF="$OUT_DIR/proof.json"
PUBLIC="$OUT_DIR/public.json"

# Groth16 needs a verification key for verify
VKEY="$OUT_DIR/verification_key.json"

die() { echo "[!] $*" >&2; exit 1; }

[[ -n "$CIRCOM" ]]  || die "CIRCOM is empty"
[[ -n "$SNARKJS" ]] || die "snarkjs not found. Set SNARKJS=/path/to/snarkjs"
[[ -n "$NODE" ]]    || die "node not found. Set NODE=/path/to/node"

[[ -f "$CIRCUIT_SRC" ]] || die "Missing $CIRCUIT_SRC in current directory"
[[ -f "$INPUT_JSON"  ]] || die "Missing $INPUT_JSON in current directory"
[[ -f "$PTAU"        ]] || die "PTAU not found: $PTAU (set PTAU=...)"

echo "[*] Tooling:"
echo "    circom : $(command -v "$CIRCOM" || echo "$CIRCOM")"
echo "    node   : $NODE"
echo "    snarkjs : $SNARKJS"
"$NODE" --version || true
"$SNARKJS" --version || true
echo

echo "[*] Cleaning outputs in ./$OUT_DIR ..."
rm -rf "./$OUT_DIR"
mkdir -p "./$OUT_DIR"

echo "[*] circom compile -> ./$OUT_DIR"
"$CIRCOM" --output "./$OUT_DIR" \
  --r1cs --sym --wasm --c --json \
  --prime "$PRIME" --"$OPT" \
  "./$CIRCUIT_SRC"

echo "[*] witness (nodejs)"
"$NODE" "./$GEN_WTN" "./$WASM" "./$INPUT_JSON" "./$WTNS"

echo "[*] witness sanity check (r1cs vs wtns)"
"$SNARKJS" wtns check "./$R1CS" "./$WTNS"

echo "[*] groth16 setup (regenerate zkey from scratch)"
rm -f "./$ZKEY" "./$PROOF" "./$PUBLIC" "./$VKEY"
"$SNARKJS" groth16 setup "./$R1CS" "./$PTAU" "./$ZKEY"

echo "[*] zkey sanity info"
"$SNARKJS" file info "./$ZKEY" || true

echo "[*] export verification key"
"$SNARKJS" zkey export verificationkey "./$ZKEY" "./$VKEY"

echo "[*] groth16 prove"
set +e
"$SNARKJS" groth16 prove "./$ZKEY" "./$WTNS" "./$PROOF" "./$PUBLIC"
rc=$?
set -e

if [[ $rc -ne 0 ]]; then
  echo "[!] groth16 prove failed (rc=$rc)."

  if [[ "$TRY_FULLPROVE" == "1" ]]; then
    echo "[*] trying groth16 fullprove (single code path)"
    rm -f "./$PROOF" "./$PUBLIC"
    "$SNARKJS" groth16 fullprove "./$INPUT_JSON" "./$WASM" "./$ZKEY" "./$PROOF" "./$PUBLIC"
    echo "[+] fullprove succeeded"
  else
    exit $rc
  fi
fi

echo "[*] groth16 verify"
"$SNARKJS" groth16 verify "./$VKEY" "./$PUBLIC" "./$PROOF"

echo "[+] Done"
