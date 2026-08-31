# mnv2_depthwise_phase8c

Phase 8C adds the **actual RISC-V custom-instruction execution path in Renode**.

The hardware RTL remains the verified Expansion -> Depthwise -> Projection
accelerator from the earlier phases. Renode uses a functional Python model
of the same accelerator behavior to execute the custom instructions.

## Architecture

RISC-V software
    |
    | custom-0 R-format instruction
    v
Renode RISC-V CPU
    |
    | custom instruction handler
    v
renode/mnv2_depthwise_cfu.py
    |
    v
Expansion -> Depthwise -> Projection functional model

The Verilog RTL is still independently verified under `sim/`.

## Custom instruction

R-format:

- opcode = `0x0B` (custom-0)
- funct3 = `0`
- funct7 = function ID
- rs1 = input 0
- rs2 = input 1
- rd = result

Function IDs:

0 LOAD_IFMAP
1 LOAD_EXP_W
2 LOAD_DW_W
3 LOAD_PROJ_W
4 START
5 STATUS
6 READ_OUTPUT

## Build software

Install a RISC-V bare-metal toolchain providing `riscv32-unknown-elf-gcc`,
then:

```bash
cd sw
make
```

This creates:

```text
mnv2_depthwise.elf
mnv2_depthwise.bin
```

## Run in Renode

From the project root:

```bash
renode renode/mnv2_depthwise.resc
```

Load the ELF from the Renode monitor:

```text
sysbus LoadELF @sw/mnv2_depthwise.elf
start
```

The program writes `0x60000000` to `mnv2_result` on success.

## Important distinction

This phase uses a Renode Python functional model for the custom instruction
behavior. It does **not** mean Renode is directly simulating the Verilog RTL.

For direct Verilog-in-the-loop Renode co-simulation, the next step is to
Verilate the RTL and connect it through Renode's CoSimulated CFU support.

References:
- Renode RISC-V custom instructions:
  https://renode.readthedocs.io/en/latest/basic/configuring-a-risc-v-cpu.html
- Renode Verilator co-simulation:
  https://renode.readthedocs.io/en/latest/tutorials/co-simulating-custom-hdl.html
