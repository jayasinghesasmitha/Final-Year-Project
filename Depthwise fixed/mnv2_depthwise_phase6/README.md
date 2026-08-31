# mnv2_depthwise_phase6

Standalone Phase 6 of the MobileNetV2-style accelerator project.

## Purpose

Phase 4C-FIX verified the expansion + depthwise + projection datapath.

Phase 5 verified a custom CFU wrapper.

Phase 6 replaces that prototype command interface with the standard
CFU-Playground-style hardware contract:

```text
RISC-V CUSTOM0 instruction
        |
        v
mnv2_depthwise_cfu
        |
        v
mnv2_depthwise_top
        |
   +----+----+
   |    |    |
 Expansion Depthwise Projection
        |
      Output
```

CFU function IDs:

```text
0  load IFMAP
1  load expansion weight
2  load depthwise weight
3  load projection weight
4  start
5  status
6  read output
```

## Run the Phase 6 RTL test

```bash
cd sim
make clean
make
```

Expected result:

```text
PHASE6 PASS: CFU load/start/read path and 256 outputs verified.
```

## Waveform

After `make`:

```bash
make wave
```

If GTKWave has a host-library conflict, run it from an environment without
the conflicting library path or use a locally installed GTKWave package.

## Important

This project is independent of the CFU-Playground source tree.

The CFU-Playground repository is not modified or required to be copied into
this project.

The RISC-V software in `software/` shows the intended CUSTOM0 API. The exact
Renode/SoC bridge is the next integration step and must match the RISC-V
platform used by the already-tested CFU-Playground environment.
