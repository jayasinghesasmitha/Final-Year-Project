# CFU Playground Setup and Run Guide

This guide documents the exact steps I followed to successfully set up and run the CFU Playground with Renode simulation on Ubuntu.

## Prerequisites

- Ubuntu 22.04 or 24.04
- Internet connection
- Git, Make, Python3, and Conda installed

---

## Setup Steps

### Step 1: Clone the Repository

```bash
cd ~/Documents
mkdir -p github
cd github
git clone https://github.com/google/CFU-Playground.git
cd CFU-Playground
```

### Step 2: Run the Setup Script

```bash
./scripts/setup
```

This updates submodules, downloads Renode, and installs missing Linux packages.

### Step 3: Create the Conda Environment

```bash
make env
```

This creates the `cfu-common` Conda environment with all required tools (RISC-V toolchain, Verilator, Yosys, NextPNR, etc.).

### Step 4: Activate the Conda Environment

```bash
source ~/Documents/github/CFU-Playground/env/conda/bin/activate cfu-common
```

After activation, the prompt changes from `(base)` to `(cfu-common)`.

### Step 5: Download and Install the RISC-V Toolchain

The system toolchain (`/usr/bin/riscv64-unknown-elf-gcc`) does not support the `zicsr` extension required by the build system.

```bash
cd ~/Documents/github/CFU-Playground

# Download the toolchain
wget https://github.com/riscv-collab/riscv-gnu-toolchain/releases/download/2023.06.02/riscv64-elf-ubuntu-20.04-nightly-2023.06.02-nightly.tar.gz

# Extract it (creates directory called 'riscv')
tar -xzf riscv64-elf-ubuntu-20.04-nightly-2023.06.02-nightly.tar.gz

# Move to a standard location
mv riscv ~/riscv-toolchain

# Add to PATH
export PATH=$HOME/riscv-toolchain/bin:$PATH
```

### Step 6: Modify Build System for `zicsr` Support

The build system needs to pass the `zicsr` flag to the assembler. Edit the `common.mak` file:

```bash
cd ~/Documents/github/CFU-Playground
nano third_party/python/litex/litex/soc/software/common.mak
```

Find the `compile` and `assemble` rules and modify them to:

```makefile
define compile
$(CC) -c $(CFLAGS) -march=rv32i2p0_m_zicsr $(1) $< -o $@
endef

define assemble
$(CC) -c $(CFLAGS) -march=rv32i2p0_m_zicsr -o $@ $<
endef
```

Save and exit (Ctrl+O, Enter, Ctrl+X).

Go to scripts/generate_renode_scripts.py

```makefile
cpu:
    cpuType: "rv32im_zicsr"
    init:
        RegisterCustomCSR "BPM" 0xB04  User
        RegisterCustomCSR "BPM" 0xB05  User
```

---

## Running the Simulation

### Step 1: Navigate to the MobileNetV2 Project

```bash
cd ~/Documents/github/CFU-Playground/proj/mnv2_first
```

### Step 2: Build and Run

```bash
make clean
make renode
```

### Step 3: Interact with the Menu

Once Renode starts, you'll see the CFU Playground menu:

```
Hello, World!
CFU Playground
==============
 1: TfLM Models menu
 2: Functional CFU Tests
 3: Project menu
 4: Performance Counter Tests
 5: TFLite Unit Tests
 6: Benchmarks
 7: Util Tests
 8: Embench IoT
main>
```

#### Run MobileNetV2 Inference:

```
main> 1                          # Enter TfLM Models menu
models> 2                        # Select MobileNetV2
mnv2> 0                          # Run test 0
```

#### Verify Correctness with Golden Test:

```
mnv2> g                          # Run golden test
```

#### Exit the Menu:

```
mnv2> x                          # Exit MobileNetV2 menu
models> x                        # Exit TfLM Models menu
```

### Step 4: Stop Renode

Press `Ctrl+C` in the Renode terminal, or type `quit` in the Renode Monitor window.

---

## Quick Restart Commands

To restart the simulation after stopping:

```bash
cd ~/Documents/github/CFU-Playground
source env/conda/bin/activate cfu-common
export PATH=$HOME/riscv-toolchain/bin:$PATH
cd proj/mnv2_first
make renode
```
