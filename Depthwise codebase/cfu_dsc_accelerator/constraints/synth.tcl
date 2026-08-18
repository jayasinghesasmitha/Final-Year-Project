/*******************************************************************************
 * CFU DSC Accelerator - Synthesis Script
 *
 * Vivado synthesis script for Xilinx Artix-7
 ******************************************************************************/

# Set project name and directories
set project_name "cfu_dsc_accelerator"
set src_dir "../rtl"
set cfu_dir "../cfu"
set constraints_dir "../constraints"
set output_dir "./output"

# Create output directory
file mkdir $output_dir

# Create project
create_project -force $project_name $output_dir -part xc7a100tcsg324-1

# Set project properties
set_property target_language Verilog [current_project]
set_property default_lib work [current_project]

# Add RTL source files
read_verilog {
    ${src_dir}/cfu_dsc_defines.v
    ${src_dir}/expansion_engine.v
    ${src_dir}/expansion_unit.v
    ${src_dir}/depthwise_unit.v
    ${src_dir}/projection_engine.v
    ${src_dir}/projection_unit.v
    ${src_dir}/post_processing_unit.v
    ${src_dir}/ifmap_buffer.v
    ${src_dir}/expansion_filter_buffer.v
    ${src_dir}/depthwise_filter_buffer.v
    ${src_dir}/instruction_controller.v
}

# Add CFU files
read_verilog {
    ${cfu_dir}/cfu_dsc_interface.v
    ${cfu_dir}/cfu_dsc_accelerator.v
}

# Add constraints
read_xdc ${constraints_dir}/artix7.xdc

# Run synthesis
synth_design -top cfu_dsc_accelerator -flatten_hierarchy rebuilt

# Write checkpoint
write_checkpoint -force ${output_dir}/post_synth.dcp

# Generate reports
report_timing_summary -file ${output_dir}/timing_summary.rpt
report_utilization -file ${output_dir}/utilization.rpt
report_power -file ${output_dir}/power.rpt

# Run optimization
opt_design
place_design
phys_opt_design
route_design

# Write final checkpoint
write_checkpoint -force ${output_dir}/post_route.dcp

# Generate bitstream (optional)
# write_bitstream -force ${output_dir}/cfu_dsc.bit

# Final reports
report_timing_summary -file ${output_dir}/timing_summary_final.rpt
report_utilization -file ${output_dir}/utilization_final.rpt
report_power -file ${output_dir}/power_final.rpt

puts "Synthesis complete!"
puts "Output directory: $output_dir"
