# MNv2 Depthwise — Phase 8D

Phase 8D is the first stage that executes a real RISC-V ELF in Renode and
decodes the seven `custom-0` instructions used by the MNv2 accelerator.

## Function IDs

| funct7 | Operation |
|---:|---|
| 0 | Load IFMAP |
| 1 | Load expansion weight |
| 2 | Load depthwise weight |
| 3 | Load projection weight |
| 4 | Start |
| 5 | Status |
| 6 | Read output |

The instruction format is:

`funct7 | rs2 | rs1 | funct3=000 | rd | opcode=0001011`

Renode installs one Python custom-instruction handler for each `funct7`.

## Build

Install a RISC-V bare-metal compiler such as `riscv32-unknown-elf-gcc`.

```bash
make
```

This creates:

`sw/mnv2_depthwise.elf`

## Run in Renode

```bash
make renode
```

Expected UART output:

```text
MNv2 Depthwise Phase 8D
Loading IFMAP...
Loading expansion weights...
Loading depthwise weights...
Loading projection weights...
Starting accelerator...
Checking outputs...
PHASE8D PASS
RISC-V custom-0 CFU path verified.
```

## Important scope

The Renode model in Phase 8D is a functional Python model of the same
algorithm and CFU instruction boundary. It is NOT yet the actual Verilog
datapath running inside Renode.

The next stage is Phase 8E: Verilate the verified Verilog CFU and connect
the actual HDL model to Renode using the CFU co-simulation interface.
