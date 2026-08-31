# mnv2_depthwise — Phase 2

Phase 2 adds a standalone CPU-facing CFU wrapper and a software test interface around the
Phase 1 Expansion, Depthwise, and Projection units.

This phase is intentionally a deterministic simulation target. It does not yet claim
compatibility with a particular Renode CPU model or FPGA SoC. The CFU register protocol
is defined here first so Phase 3 can map it onto a RISC-V/ Renode system cleanly.

## CFU command protocol

`cmd` is 4 bits:

- 0x0 CONFIG
- 0x1 LOAD_IFMAP
- 0x2 LOAD_EXP_WEIGHT
- 0x3 LOAD_DW_WEIGHT
- 0x4 LOAD_PROJ_WEIGHT
- 0x5 START
- 0x6 STATUS
- 0x7 READ_OUTPUT

`data` is 32 bits.

CONFIG packs H[7:0], W[15:8], CIN[23:16], CEXP[31:24].
The Phase 2 reference configuration is 4x4, 8 -> 24 -> 16.

The wrapper contains small memories and explicit write addresses. This is the key architectural
difference from the old standalone depthwise repository, where several addresses were dangling.

## Run

```bash
cd sim
make
```

Expected:

```text
CFU CONFIG PASS
CFU LOAD PASS
CFU START PASS
CFU OUTPUT PASS
Phase 2 CFU test passed.
```

## Important

This is a CPU-facing RTL wrapper, not yet a full Renode machine. Renode requires a RISC-V SoC/peripheral
model and firmware. Those are added in Phase 3.
