# CFU DSC Accelerator

**Fused Depthwise Separable Convolution Accelerator for MobileNetV2**

A RISC-V Custom Function Unit (CFU) implementing fused pixel-wise dataflow for Expansion → Depthwise → Projection convolution pipeline. This design eliminates intermediate feature map buffering entirely, achieving up to 87% reduction in memory traffic compared to layer-by-layer execution.

## Overview

This accelerator implements the architecture described in:
> "RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI"

### Key Features

- **Fused Pixel-wise Dataflow**: Computes one output pixel completely through all three stages without intermediate buffering
- **5-Stage Intra-Stage Pipeline**: Maximum hardware utilization with minimal idle cycles
- **9 Parallel Expansion Engines**: 8-way MAC tree per engine, Input-Stationary dataflow
- **56 Parallel Projection Engines**: Output-Stationary dataflow with distributed LUTRAM
- **On-the-Fly Padding**: Hardware-managed padding eliminates explicit tensor expansion
- **INT8 Quantization**: Native support for TensorFlow Lite quantized models

### Architecture Diagram

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         CFU DSC Accelerator                                  │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│   ┌──────────────┐                                                          │
│   │  IFMAP Buffer│  9-bank parallel BRAM                                     │
│   │  (9 banks)   │                                                          │
│   └──────┬───────┘                                                          │
│          │ 3x3 window                                                        │
│          ▼                                                                   │
│   ┌─────────────────────────────────────────────────────────┐               │
│   │              EXPANSION UNIT (9 Engines)                  │               │
│   │  ┌─────────┐ ┌─────────┐         ┌─────────┐            │               │
│   │  │ Engine 0│ │ Engine 1│  ...    │ Engine 8│            │               │
│   │  │ 8-way   │ │ 8-way   │         │ 8-way   │            │               │
│   │  │ MAC     │ │ MAC     │         │ MAC     │            │               │
│   │  └────┬────┘ └────┬────┘         └────┬────┘            │               │
│   │       └────────────┴───────────────────┘                │               │
│   │                    │                                     │               │
│   │       ┌────────────▼────────────┐                       │               │
│   │       │   Post-Processing       │                       │               │
│   │       │  (Bias + Requant + ReLU)│                       │               │
│   │       └────────────┬────────────┘                       │               │
│   └────────────────────┼────────────────────────────────────┘               │
│                        │ 3x3 tile (F1)                                      │
│                        ▼                                                    │
│   ┌─────────────────────────────────────────┐                               │
│   │           DEPTHWISE UNIT               │                               │
│   │      ┌───────────────────┐             │                               │
│   │      │   9-way MAC Array │             │                               │
│   │      │  (3x3 convolution)│             │                               │
│   │      └─────────┬─────────┘             │                               │
│   │                │                       │                               │
│   │    ┌───────────▼───────────┐           │                               │
│   │    │  Post-Processing      │           │                               │
│   │    └───────────┬───────────┘           │                               │
│   └────────────────┼───────────────────────┘                               │
│                    │ single element (F2)                                   │
│                    ▼                                                        │
│   ┌─────────────────────────────────────────────────────────┐               │
│   │              PROJECTION UNIT (56 Engines)                │               │
│   │  ┌─────────┐ ┌─────────┐         ┌─────────┐            │               │
│   │  │ Engine 0│ │ Engine 1│  ...    │ Engine 55│           │               │
│   │  │Private  │ │Private  │         │Private  │            │               │
│   │  │Weights  │ │Weights  │         │Weights  │            │               │
│   │  │(LUTRAM) │ │(LUTRAM) │         │(LUTRAM) │            │               │
│   │  └────┬────┘ └────┬────┘         └────┬────┘            │               │
│   │       └────────────┴───────────────────┘                │               │
│   │                    │                                     │               │
│   │       ┌────────────▼────────────┐                       │               │
│   │       │   Post-Processing       │                       │               │
│   │       └────────────┬────────────┘                       │               │
│   └────────────────────┼────────────────────────────────────┘               │
│                        │ 56 output channels                                 │
│                        ▼                                                    │
│   ┌─────────────────────────────────────────┐                               │
│   │         CPU Read Interface             │                               │
│   └─────────────────────────────────────────┘                               │
│                                                                              │
└─────────────────────────────────────────────────────────────────────────────┘
```

## File Structure

```
cfu_dsc_accelerator/
├── rtl/                          # RTL Source Files
│   ├── cfu_dsc_defines.v         # Common definitions and parameters
│   ├── expansion_engine.v        # Single expansion engine (8-way MAC)
│   ├── expansion_unit.v          # 9 parallel expansion engines
│   ├── depthwise_unit.v          # Depthwise convolution unit
│   ├── projection_engine.v       # Single projection engine
│   ├── projection_unit.v         # 56 parallel projection engines
│   ├── post_processing_unit.v    # Bias + Requantization + ReLU
│   ├── ifmap_buffer.v            # 9-bank IFMAP buffer with padding
│   ├── expansion_filter_buffer.v # Expansion weight storage
│   ├── depthwise_filter_buffer.v # Depthwise weight storage (9-bank)
│   └── instruction_controller.v  # Control FSM
│
├── cfu/                          # CFU Integration
│   ├── cfu_dsc_interface.v       # CFU-Playground interface
│   └── cfu_dsc_accelerator.v     # Top-level accelerator module
│
├── software/                     # Software Drivers
│   ├── cfu_dsc_driver.h          # Driver header file
│   ├── cfu_dsc_driver.c          # Driver implementation
│   └── tflm_kernel.h             # TensorFlow Lite Micro integration
│
├── sim/                          # Simulation
│   ├── Makefile                  # Build system
│   ├── tb_cfu_dsc_accelerator.v  # Top-level testbench
│   └── tb_expansion_engine.v     # Unit testbench example
│
└── README.md                     # This file
```

## Hardware Architecture

### 5-Stage Intra-Stage Pipeline

```
Cycle:  1      2      3      4      5      6      7
        │      │      │      │      │      │      │
Pixel 1: [EXP_MAC][EXP_Q][DW_MAC][DW_Q][PROJ_MAC]───┐
Pixel 2:        [EXP_MAC][EXP_Q][DW_MAC][DW_Q][PROJ_MAC]
Pixel 3:               [EXP_MAC][EXP_Q][DW_MAC][DW_Q][PROJ_MAC]
Pixel 4:                      [EXP_MAC][EXP_Q][DW_MAC][DW_Q]...
```

### Expansion Unit

| Parameter | Value |
|-----------|-------|
| Engines | 9 (for 3x3 spatial tile) |
| MAC per Engine | 8-way |
| Dataflow | Input-Stationary |
| Throughput | 72 MACs/cycle |

### Depthwise Unit

| Parameter | Value |
|-----------|-------|
| Engines | 1 |
| MAC Array | 9-way (3x3) |
| Dataflow | No Local Reuse (NLR) |
| Throughput | 9 MACs/cycle |

### Projection Unit

| Parameter | Value |
|-----------|-------|
| Engines | 56 |
| Weight Storage | Distributed LUTRAM per engine |
| Dataflow | Output-Stationary |
| Throughput | 56 MACs/cycle |

## Usage

### Hardware Integration

1. **Add to your CFU-Playground project:**

```verilog
// In your SoC top level
cfu_dsc_accelerator u_cfu (
    .clk        (sys_clk),
    .rst_n      (sys_rst_n),
    .funct3     (cfu_funct3),
    .funct7     (cfu_funct7),
    .rs1        (cfu_rs1),
    .rs2        (cfu_rs2),
    .rd         (cfu_rd),
    .cfu_start  (cfu_start),
    .cfu_done   (cfu_done)
);
```

### Software Usage

```c
#include "cfu_dsc_driver.h"

// Initialize
cfu_dsc_init();

// Configure dimensions
cfu_dsc_config_t config = {
    .height = 14,
    .width = 14,
    .in_channels = 32,
    .exp_channels = 96,
    .out_channels = 32,
    // ... quantization params
};
cfu_dsc_configure(&config);

// Load data
cfu_dsc_load_ifmap(input_data, size);
cfu_dsc_load_expansion_weights(exp_weights, 96, 32);
cfu_dsc_load_depthwise_weights(dw_weights, 96);
cfu_dsc_load_projection_weights(proj_weights, 32, 96);

// Execute
cfu_dsc_start();
cfu_dsc_wait_done();

// Read output
cfu_dsc_read_all_outputs(output_buffer, 32);
```

### TensorFlow Lite Micro Integration

```c
// Register the custom op
auto registration = Register_CFUDSC_DEPTHWISE_CONV_2D();
interpreter->AddCustom("CFUDscDepthwiseConv2D", registration);
```

## Simulation

### Requirements

- Icarus Verilog (iverilog)
- GTKWave (for waveform viewing)
- GNU Make

### Running Tests

```bash
cd sim/

# Run full testbench
make sim

# View waveforms
make wave

# Run unit tests
make test_expansion
make test_depthwise
make test_projection

# Clean
make clean
```

## Synthesis

### FPGA Target: Xilinx Artix-7 (Nexys A7-100T)

Expected resource utilization:

| Resource | Expected | Available |
|----------|----------|-----------|
| LUTs | ~21,000 | 63,400 |
| FFs | ~18,000 | 126,800 |
| BRAM (36Kb) | ~97 | 135 |
| DSP Slices | ~178 | 240 |

### Timing

- Target frequency: 100 MHz
- Pipeline stages: 5
- Latency per pixel: ~5 cycles
- Throughput: 1 pixel/cycle (at steady state)

## CFU Instruction Set

### Function IDs (funct3)

| funct3 | Operation |
|--------|-----------|
| 0 | READ output channel |
| 1 | WRITE data/weights |
| 2 | EXECUTE command |
| 3 | GET status |

### Write Commands (funct7)

| funct7 | Data Type |
|--------|-----------|
| 0 | IFMAP pixel |
| 1 | Expansion weight |
| 2 | Depthwise weight |
| 3 | Projection weight |
| 4 | Bias value |

### Execute Commands (funct7)

| funct7 | Command |
|--------|---------|
| 0 | Set dimensions (height, width) |
| 1 | Set channels (in, exp) |
| 2 | Set output channels |
| 7 | START computation |

## Performance

### Speedup (from paper)

| Version | Speedup vs Software |
|---------|---------------------|
| v1 (Sequential) | 27.4× |
| v2 (Inter-stage pipeline) | 46.3× |
| v3 (Intra-stage pipeline) | 59.3× |

### Memory Traffic Reduction

- Intermediate F1, F2 feature maps: **0 bytes** (zero buffering)
- Total data movement reduction: **87%** vs layer-by-layer

## References

1. M. Yildirim, "RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI"
2. CFU-Playground: https://github.com/google/CFU-Playground
3. MobileNetV2: Sandler et al., "MobileNetV2: Inverted Residuals and Linear Bottlenecks"

## License

This implementation is provided for research and educational purposes.

## Acknowledgments

This implementation is based on the architecture described in the paper "RISC-V Based TinyML Accelerator for Depthwise Separable Convolutions in Edge AI" by Muhammed Yildirim.
