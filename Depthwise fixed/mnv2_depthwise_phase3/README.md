# mnv2_depthwise — Phase 3: Integrated datapath

This phase combines the independently verified Phase 1 compute units into a real
Expansion -> Depthwise -> Projection datapath behind the Phase 2 CFU command interface.

Reference configuration:
- H=4, W=4
- CIN=8
- CEXP=24
- COUT=16
- signed INT8 data/weights
- 32-bit accumulation

The Phase 3 integration is intentionally a small deterministic streaming engine.
It processes one spatial location per start command and exposes an explicit LOAD/START/READ
protocol. This makes the datapath easy to verify before adding a cycle-accurate controller
and RISC-V/Renode integration.

Run:

```bash
cd sim
make
```

Expected final line:

```text
Phase 3 integrated datapath test passed.
```

This project remains independent from CFU-Playground.
