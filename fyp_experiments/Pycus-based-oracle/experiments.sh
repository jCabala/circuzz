#!/usr/bin/env bash
set -euo pipefail

# Minimal experiments runner for Pycus-based-oracle
# Usage: ./experiments.sh [IMAGE_NAME]
# Default IMAGE_NAME: picus-test

IMAGE_NAME="${1:-picus-test}"

# choose a random seed
SEED=${RANDOM}

OBJ_DIR="./obj/seed-${SEED}"
EXPLORE_WORK_DIR="${OBJ_DIR}/explore/working"
EXPLORE_REPORT_DIR="${OBJ_DIR}/explore/report"

mkdir -p "${EXPLORE_WORK_DIR}"
mkdir -p "${EXPLORE_REPORT_DIR}"

echo "Running exploration with image=${IMAGE_NAME} seed=${SEED}"

# mount repo into /app and run the explorer
podman run --rm -v "${PWD}":/app -w /app "${IMAGE_NAME}" \
  python3 cli.py explore --tool circom --working-dir "/app/${EXPLORE_WORK_DIR}" --report-dir "/app/${EXPLORE_REPORT_DIR}" --seed ${SEED} --timeout "0h0m30s"

echo "Explore finished. Reports are in ${EXPLORE_REPORT_DIR}"
