# mnv2_depthwise

Standalone MobileNetV2-style depthwise-separable convolution hardware project.

Phase 1 implements and verifies the three computational stages independently:

1. Expansion 1x1: 8 input channels -> 24 expanded channels
2. Depthwise 3x3: 24 channels -> 24 channels, one kernel per channel
3. Projection 1x1: 24 input channels -> 16 output channels

The RTL is plain SystemVerilog/Verilog-2001 compatible and does not depend on CFU-Playground.

## Run Phase 1 simulation

Requirements:
- iverilog
- vvp
- Python 3

```bash
cd sim
make
make test
```

The testbench uses deterministic signed INT8 values and checks every stage against the expected arithmetic.

## Structure

```text
rtl/
  expansion/
  depthwise/
  projection/
sim/
  tb_expansion.v
  tb_depthwise.v
  tb_projection.v
  reference_model.py
vivado/
  create_project.tcl
  run_sim.tcl
```

Later phases can add the controller, buffers, CFU interface, RISC-V software, Renode integration, and Nexys4DDR top level.
