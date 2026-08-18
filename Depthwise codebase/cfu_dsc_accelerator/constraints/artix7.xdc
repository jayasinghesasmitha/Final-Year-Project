################################################################################
# CFU DSC Accelerator - Xilinx Artix-7 Constraints
#
# Target Board: Digilent Nexys A4 DDR / Nexys A7-100T
# FPGA: XC7A100T-1CSG324C
# Clock: 100 MHz
################################################################################

#===============================================================================
# Clock Constraints
#===============================================================================

# System clock (100 MHz)
create_clock -period 10.000 -name sys_clk -waveform {0.000 5.000} [get_ports clk]

# Set clock uncertainty
set_clock_uncertainty -setup 0.200 [get_clocks sys_clk]
set_clock_uncertainty -hold 0.050 [get_clocks sys_clk]

#===============================================================================
# Input/Output Delay Constraints
#===============================================================================

# CFU interface inputs (from VexRiscv)
set_input_delay -clock sys_clk -max 2.000 [get_ports {funct3 funct7 rs1 rs2}]
set_input_delay -clock sys_clk -min 0.500 [get_ports {funct3 funct7 rs1 rs2}]
set_input_delay -clock sys_clk -max 2.000 [get_ports cfu_start]
set_input_delay -clock sys_clk -min 0.500 [get_ports cfu_start]

# CFU interface outputs (to VexRiscv)
set_output_delay -clock sys_clk -max 2.000 [get_ports {rd cfu_done}]
set_output_delay -clock sys_clk -min 0.500 [get_ports {rd cfu_done}]

# Reset input
set_input_delay -clock sys_clk -max 5.000 [get_ports rst_n]
set_input_delay -clock sys_clk -min 1.000 [get_ports rst_n]

#===============================================================================
# False Paths
#===============================================================================

# Reset is asynchronous
set_false_path -from [get_ports rst_n]

# Configuration registers are static during computation
set_false_path -to [get_cells -hierarchical -filter {NAME =~ *cfg_*}]

#===============================================================================
# Multi-Cycle Paths
#===============================================================================

# Post-processing pipeline has 4 stages
set_multicycle_path -setup 4 -from [get_cells -hierarchical -filter {NAME =~ *expansion_unit*}] -to [get_cells -hierarchical -filter {NAME =~ *f1_valid*}]
set_multicycle_path -hold 3 -from [get_cells -hierarchical -filter {NAME =~ *expansion_unit*}] -to [get_cells -hierarchical -filter {NAME =~ *f1_valid*}]

#===============================================================================
# Area Constraints
#===============================================================================

# Keep expansion engines together
create_pblock expansion_block
resize_pblock expansion_block -add {SLICE_X0Y0:SLICE_X50Y50}
add_cells_to_pblock expansion_block [get_cells -hierarchical -filter {NAME =~ *exp_engines*}]

# Keep projection engines together
create_pblock projection_block
resize_pblock projection_block -add {SLICE_X50Y0:SLICE_X100Y100}
add_cells_to_pblock projection_block [get_cells -hierarchical -filter {NAME =~ *proj_engines*}]

#===============================================================================
# BRAM Constraints
#===============================================================================

# IFMAP buffer in BRAM
set_property RAM_STYLE block [get_cells -hierarchical -filter {NAME =~ *ifmap_buf*bank*}]

# Filter buffers in BRAM
set_property RAM_STYLE block [get_cells -hierarchical -filter {NAME =~ *exp_fbuf*mem*}]
set_property RAM_STYLE block [get_cells -hierarchical -filter {NAME =~ *dw_fbuf*bank*}]

# Projection weights in distributed RAM (LUTRAM)
set_property RAM_STYLE distributed [get_cells -hierarchical -filter {NAME =~ *proj_engines*weight*}]

#===============================================================================
# DSP Constraints
#===============================================================================

# Use DSP slices for multipliers
set_property USE_DSP48 YES [get_cells -hierarchical -filter {NAME =~ *product_*}]
set_property USE_DSP48 YES [get_cells -hierarchical -filter {NAME =~ *mac*}]

#===============================================================================
# Timing Exceptions
#===============================================================================

# Pipeline registers can have relaxed timing
set_property REGISTER_BALANCING ON [get_nets -hierarchical -filter {NAME =~ *pipeline*}]

#===============================================================================
# Power Constraints
#===============================================================================

# Enable clock gating where possible
set_property CLOCK_GATE_ENABLE TRUE [get_cells -hierarchical -filter {NAME =~ *pipeline_enable*}]

#===============================================================================
# Debug Constraints (optional)
#===============================================================================

# Mark debug signals
set_property MARK_DEBUG TRUE [get_ports {cfu_start cfu_done}]
set_property MARK_DEBUG TRUE [get_cells -hierarchical -filter {NAME =~ *status*}]

#===============================================================================
# Implementation Strategy
#===============================================================================

# Use performance optimized strategy
set_property strategy Performance_Explore [get_runs impl_1]
