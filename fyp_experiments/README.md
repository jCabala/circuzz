# Experiments

## circom-picus

### Overview

`picus` is a tool allowing to detect underconstraint inputs. This experiments tries to use it as a metamorphic oracle instead of normal `circuzz` oracles.

### How to run

```bash
cd fyp_experiments/circom-picus
chmod +x ./experiments.sh

./experiment.sh
```

The report together with logs will be stored under `circom-picus/obj` directory.
You can modify the duration of the experiment in the `expderiments.sh` file.
The logs will contain all of the generated circuits.

# Changelog

1. Added a picus oracle to circom. It can be enabled using `circom {oracle: "picus"}` in config file.

2. Developed a `circom-picus` experiment
