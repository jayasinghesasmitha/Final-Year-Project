# mnv2_depthwise — Phase 4B

Phase 4B completes the clocked datapath integration:

IFMAP RAM -> Expansion -> Expanded Feature RAM -> Depthwise -> Depthwise RAM -> Projection -> Output RAM

The implementation uses explicit linear addresses and one compute operation per clock for
the baseline engines. The testbench verifies the numerical output for a 4x4, 8->24->16
configuration.

Run:

```bash
cd sim
make clean
make
```

Expected:

```text
PHASE4B PASS
```

The design is still a baseline architecture. Parallel DSP replication, quantization,
CFU/RISC-V integration and Renode are later phases.
