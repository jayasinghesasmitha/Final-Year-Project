# Gemmini NPU Simulation Setup Guide

A complete guide to installing Chipyard with Gemmini DNN accelerator and running your first NPU simulations on Ubuntu.

## System Requirements

- **OS**: Ubuntu 20.04 or 22.04 (64-bit)
- **RAM**: 16GB minimum (8GB with settings adjustment)
- **Storage**: 50-100GB free space
- **CPU**: Multiple cores recommended

## Quick Start

### 1. Install System Dependencies

```bash
# Basic build tools and libraries
sudo apt-get update
sudo apt-get install -y build-essential git curl
sudo apt-get install -y libgmp-dev libmpfr-dev libmpc-dev zlib1g-dev
sudo apt-get install -y default-jdk
sudo apt-get install -y cmake ninja-build
sudo apt-get install -y python3-pip

# Additional dependencies
sudo apt-get install -y bison flex software-properties-common
sudo apt-get install -y texinfo gengetopt
sudo apt-get install -y libexpat1-dev libusb-dev libncurses5-dev
sudo apt-get install -y rsync libguestfs-tools expat ctags
sudo apt-get install -y device-tree-compiler
```

### 2. Install sbt (Scala Build Tool)

```bash
echo "deb https://repo.scala-sbt.org/scalasbt/debian /" | sudo tee -a /etc/apt/sources.list.d/sbt.list
curl -sL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x2EE0EA64E40A89B84B2DF73499E82A75642AC823" | sudo apt-key add
sudo apt-get update
sudo apt-get install -y sbt
```

### 3. Install Miniforge (Conda Alternative)

```bash
curl -L -O "https://github.com/conda-forge/miniforge/releases/latest/download/Miniforge3-$(uname)-$(uname -m).sh"
bash Miniforge3-$(uname)-$(uname -m).sh
# When prompted: type "yes" to initialize
source ~/.bashrc

# Optional: Install faster libmamba solver
conda install -n base conda-libmamba-solver -y
conda config --set solver libmamba
```

### 4. Clone and Setup Chipyard

```bash
git clone https://github.com/ucb-bar/chipyard.git
cd chipyard
```

### 5. Run Main Build Script

```bash
# This takes 2-4 hours
./build-setup.sh
```
Note: If you encounter space issues, skip FireMarshal:

```bash
./build-setup.sh -s 1 -s 9 -s 10
```

### 6. Build Gemmini Software Tests
```bash
source env.sh
cd generators/gemmini/software/gemmini-rocc-tests
./build.sh
```

### 7. Build Verilator Simulator
```bash
cd ~/chipyard/sims/verilator
make CONFIG=GemminiRocketConfig
```