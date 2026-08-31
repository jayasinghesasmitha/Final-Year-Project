# mnv2_depthwise — Phase 4

Phase 4 replaces the Phase 3 reference-style computation with an explicit clocked
hardware datapath.

Reference configuration:
- H=4, W=4
- CIN=8
- CEXP=24
- COUT=16
- signed INT8
- 32-bit accumulation
- stride 1
- zero padding for the 3x3 depthwise operation

The implementation has:
- explicit linear-address memories
- separate Expansion, Depthwise and Projection engines
- a controller FSM
- a top-level compute engine
- a cycle-by-cycle testbench

This phase is standalone and does not modify or depend on CFU-Playground.

## Run

```bash
cd sim
make
```

Expected:

```text
PHASE4 PASS
```

## Current architecture

For correctness and synthesis clarity, the Phase 4 engines use one MAC accumulation
per cycle. This is intentionally a baseline architecture. Parallel DSP replication,
channel chunking, and CFU/RISC-V integration are subsequent optimization/integration phases.

The controller performs:

LOAD_IFMAP -> LOAD_EXP_W -> LOAD_DW_W -> LOAD_PROJ_W ->
COMPUTE_EXP -> COMPUTE_DW -> COMPUTE_PROJ -> DONE.

The host/testbench supplies one byte per LOAD command and explicit addresses.
