
# mnv2_depthwise — Phase 4C fixed + Phase 5 CFU integration

## Phase 4C-FIX

The end-to-end clocked datapath is now connected and uses explicit accumulator registers:

IFMAP -> Expansion -> Expanded RAM -> Depthwise -> DW RAM -> Projection -> Output RAM

The previous X-valued output problem is fixed by not using output RAM as an intermediate
accumulator.

Run:

```bash
cd sim
make phase4c
```

Expected:

```text
PHASE4C-FIX PASS: all 256 outputs equal 192 and no X values were observed.
```

## Phase 5

Phase 5 adds a CPU-facing CFU command wrapper around the Phase 4C accelerator.

Commands:

```text
0 CONFIG
1 LOAD_IFMAP
2 LOAD_EXP_W
3 LOAD_DW_W
4 LOAD_PROJ_W
5 START
6 STATUS
7 READ_OUTPUT
```

Run:

```bash
make phase5
```

or run both:

```bash
make
```

Phase 5 is the hardware-side CFU integration baseline. A real CFU-Playground-compatible
RISC-V instruction encoding and Renode machine are intentionally deferred until this
interface is verified.

This project remains independent from CFU-Playground.
