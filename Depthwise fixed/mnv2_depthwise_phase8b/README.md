# mnv2_depthwise_phase8b

Standalone Phase 8B software/RISC-V boundary project.

The RTL datapath is carried forward from the verified Phase 7/8A
implementation.

## RTL verification

```bash
cd sim
make clean
make
```

Expected result:

```text
PHASE8B PASS
All 256 outputs equal 192.
```

## Software

`sw/cfu_instruction.h` isolates the RISC-V custom-0 instruction
boundary. `sw/mnv2_depthwise.c` provides the accelerator API.

## Renode

The `.resc` file is a scaffold. A real Renode integration requires a
Renode-side CPU/custom-instruction model; the Verilog RTL is not
automatically executable by Renode from a `.resc` file.
