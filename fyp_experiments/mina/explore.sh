#!/bin/bash

#
# This script starts an exploration for the Mina/o1js backend
# It requires that the podman-build.sh script was run beforehand!
# 

set -x
start=`date +%s`


SCRIPT_PATH=$(dirname "$(realpath "$0")")
CIRCUZZ_ROOT=$(realpath "$SCRIPT_PATH/../../")

# =================================================
#                  Configuration
# =================================================

# Config paths must be relative to CIRCUZZ_ROOT
MINA_ARITHMETIC_CONFIG=fyp_experiments/mina/config/mina-arithmetic.json
MINA_BOOLEAN_CONFIG=fyp_experiments/mina/config/mina-boolean.json

IMAGE_MINA_DEFAULT="mina-latest"

SEED=42
VERBOSITY=3
USE_TMP=1

# Timeout settings
T_SECONDS=30
T_MINUTES=0
T_HOURS=0

MINA_ARITHMETIC_NUM=1
MINA_ARITHMETIC_CPUS=1
MINA_BOOLEAN_NUM=1
MINA_BOOLEAN_CPUS=1

TMP_DIR=/tmp/circuzz/seed-$SEED-date-$start
OBJ_DIR=$SCRIPT_PATH/obj/seed-$SEED-date-$start
WAIT_BETWEEN=2

# ----------------------------- DO NOT TOUCH -----------------------------

# =================================================
#                 Implementation
# =================================================

# gives the tool extra 5m to shutdown, calculates everything into seconds
PODMAN_TIMEOUT=$((($T_HOURS * 60 * 60) + (($T_MINUTES + 5) * 60) + $T_SECONDS))
# uses the exact values given in hms format style
TOOL_TIMEOUT=$(printf "%sh%sm%ss" $T_HOURS $T_MINUTES $T_SECONDS)

# Get into the experiments directory
cd $SCRIPT_PATH

# seed randomness
RANDOM=$SEED

# create folder structure
mkdir -p $OBJ_DIR

# setup tmp file
if [[ $USE_TMP -eq 1 ]]; then
    mkdir -p $TMP_DIR
fi

# helper function (tool, image, unique-name, cpus, random, config)
function start() {
    CONFIG=$6

    echo "Starting $1 with seed $5 using config $CONFIG ..."

    EXPLORE_REP_DIR=$OBJ_DIR/$3/explore/report
    LOG_DIR_RUN=$OBJ_DIR/$3/explore/logs
    PREFIXED_EXPLORE_REP_DIR=/app/fyp_experiments/mina/obj/seed-$SEED-date-$start/$3/explore/report
    if [[ $USE_TMP -eq 1 ]]; then
        # tmp folders are cleaned above
        EXPLORE_WORK_DIR=/tmp/$3/explore/working
    else
        EXPLORE_WORK_DIR=$OBJ_DIR/$3/explore/working
    fi

    mkdir -p "$EXPLORE_REP_DIR"
    mkdir -p "$LOG_DIR_RUN"

    # start explorer
    if [[ $USE_TMP -eq 1 ]]; then
        podman run --timeout=$PODMAN_TIMEOUT --pids-limit=-1 --cpus=$4 -v $CIRCUZZ_ROOT/:/app -v $TMP_DIR:/tmp --rm $2 python3 cli.py explore --tool $1 -v$VERBOSITY --timeout $TOOL_TIMEOUT --working-dir $EXPLORE_WORK_DIR --report-dir $PREFIXED_EXPLORE_REP_DIR --seed $5 --config $CONFIG > $LOG_DIR_RUN/$3-explore.log 2>&1 &
    else
        podman run --timeout=$PODMAN_TIMEOUT --pids-limit=-1 --cpus=$4 -v $CIRCUZZ_ROOT/:/app --rm $2 python3 cli.py explore --tool $1 -v$VERBOSITY --timeout $TOOL_TIMEOUT --working-dir $EXPLORE_WORK_DIR --report-dir $PREFIXED_EXPLORE_REP_DIR --seed $5 --config $CONFIG > $LOG_DIR_RUN/$3-explore.log 2>&1 &
    fi

    wait $(jobs -p)
}

# mina arithmetic
if [[ $MINA_ARITHMETIC_NUM -ne 0 ]]; then
    for i in $(seq 1 $MINA_ARITHMETIC_NUM);
    do
        R=$RANDOM
        start mina $IMAGE_MINA_DEFAULT mina-arithmetic-$i $MINA_ARITHMETIC_CPUS $R $MINA_ARITHMETIC_CONFIG &
        echo "Started mina-arithmetic $i/$MINA_ARITHMETIC_NUM with seed $R ..."
        sleep $WAIT_BETWEEN
    done
fi

# mina boolean
if [[ $MINA_BOOLEAN_NUM -ne 0 ]]; then
    for i in $(seq 1 $MINA_BOOLEAN_NUM);
    do
        R=$RANDOM
        start mina $IMAGE_MINA_DEFAULT mina-boolean-$i $MINA_BOOLEAN_CPUS $R $MINA_BOOLEAN_CONFIG &
        echo "Started mina-boolean $i/$MINA_BOOLEAN_NUM with seed $R ..."
        sleep $WAIT_BETWEEN
    done
fi

# wait for all to finish
wait $(jobs -p)

# clean up temporary
rm -rf $TMP_DIR

end=`date +%s`
runtime=$((end-start))
echo "finished in $runtime s"
