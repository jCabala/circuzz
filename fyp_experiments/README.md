# Experiments

## circom-picus

### Overview

`picus` is a tool allowing to detect underconstraint inputs. This experiments tries to use it as a metamorphic oracle instead of normal `circuzz` oracles. It also uses the `quadratic` generator.

### How to run

```bash
cd fyp_experiments/circom-picus
chmod +x ./experiments.sh

./experiment.sh
```

The report together with logs will be stored under `circom-picus/obj` directory.
You can modify the duration of the experiment in the `expderiments.sh` file.
The logs will contain all of the generated circuits.

## Scripts
This directory contains some additionall helpful scripts.

### generate-quadratic.py
Generates couple circom programs using the quadratic generator.

# Changelog

1. Added a picus oracle to circom. It can be enabled using `circom: {oracle: "picus"}` in config file.

2. Developed a `circom-picus` experiment

3. Created [quadratic ir generator](../src/circuzz/ir/generators/quadratic.py). Can be enabled in the config by using `{generation: {generator: "quadratic"}}`

4. Added a `cosntrain-equallity-assertions` flag to circom config (`circom: {constrain_equallity_assertions: true}`) that whenever we have a assertion with expression where the op is eq it (e.g `assert(a == 2)`), it will translate it into constraints (`a === 2`). For good performance you need to ensure the cosntraints will remain quadratic (e.g quadratic ir generator) 