#!/usr/bin/env bash
set -euo pipefail

LIB=/usr/lib/x86_64-linux-gnu/faketime/libfaketime.so.1
CIRCOM_BIN=${CIRCOM_BIN:-/home/jcabala/.cargo/bin/circom}
CIRCOMLIB_DIR=${CIRCOMLIB_DIR:-/circuzz/circomlib/circuits}
CIRCUIT=${1:-$(dirname "$0")/buggy_circuit_transformed.circom}
OUT_DIR=${OUT_DIR:-/tmp/circuzz-repro/faketime-loop}
ITERATIONS=${ITERATIONS:-200}
TS_FILE=${TS_FILE:-/tmp/faketime.txt}

if [[ ! -f "$LIB" ]]; then
  echo "missing libfaketime: $LIB" >&2
  exit 2
fi

mkdir -p "$OUT_DIR"
echo "+0s x1" > "$TS_FILE"

(
  while true; do
    echo "+0s x1" > "$TS_FILE"
    sleep 0.02
    echo "-2s x1" > "$TS_FILE"
    sleep 0.02
  done
) &
JITTER_PID=$!
trap 'kill "$JITTER_PID" >/dev/null 2>&1 || true' EXIT

count=0
while [[ $count -lt $ITERATIONS ]]; do
  count=$((count + 1))
  LD_PRELOAD="$LIB" \
  FAKETIME_TIMESTAMP_FILE="$TS_FILE" \
  FAKETIME_NO_CACHE=1 \
  "$CIRCOM_BIN" \
    --output "$OUT_DIR" \
    --r1cs --sym --wasm --c --json \
    --prime pallas --O1 \
    -l "$CIRCOMLIB_DIR" \
    "$CIRCUIT" \
    >"$OUT_DIR/repro.out" 2>&1 || {
      echo "failed_at=$count"
      tail -n 120 "$OUT_DIR/repro.out"
      exit 1
    }

  if (( count % 25 == 0 )); then
    echo "ok_through=$count"
  fi
done

echo "completed=$ITERATIONS"
