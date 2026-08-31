# mnv2_depthwise_phase8

Standalone Phase 8 project for the MobileNetV2-style
Expansion -> Depthwise -> Projection accelerator.

## Baseline

`rtl/mnv2_depthwise_top.v` is the verified Phase 7 datapath.
Do not replace it with a newly rewritten datapath.

## RTL test

```bash
make clean
make
```

Phase 8A is the RTL/software boundary preparation.
The actual RISC-V custom-instruction and Renode integration is Phase 8B.

## CFU function IDs

| ID | Operation |
|---:|---|
| 0 | Load IFMAP |
| 1 | Load expansion weight |
| 2 | Load depthwise weight |
| 3 | Load projection weight |
| 4 | Start |
| 5 | Status |
| 6 | Read output |

Expected functional test output is 192 for all 256 outputs for the
unit test dataset.


## Running the Phase 8 RTL test

From the project root:

```bash
make clean
make
```

Or from the `sim/` directory:

```bash
cd sim
make clean
make
```

The simulation executable is created as `sim/tb_phase8`.
