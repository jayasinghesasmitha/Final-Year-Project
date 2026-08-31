# mnv2_depthwise — Phase 4C

Phase 4C is the first end-to-end clocked baseline.

The top-level accelerator now owns and connects:

IFMAP memory
 -> Expansion accumulation
 -> Expanded feature-map memory
 -> Depthwise 3x3 accumulation with zero padding
 -> Depthwise output memory
 -> Projection accumulation
 -> Output memory

The testbench loads real memories, starts the accelerator, waits for DONE, reads every
output and checks the result.

For the deterministic vector:
- IFMAP = 1
- Expansion weights = 1
- Depthwise kernel = center-only 1
- Projection weights = 1

Expected output for every spatial position/output channel is 192.

Run:

```bash
cd sim
make clean
make
```

This is still a baseline one-MAC-per-clock architecture. It is intended as the correctness
reference before parallel DSP replication and CFU/RISC-V integration.

The old Phase 4B controller/engine files are retained for comparison, but the active
top-level simulation uses `rtl/mnv2_depthwise_top.v`.
