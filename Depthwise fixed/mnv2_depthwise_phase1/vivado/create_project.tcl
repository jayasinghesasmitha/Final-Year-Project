# Create a standalone Vivado RTL project for Phase 1.
# Change PART if a different FPGA board is used.

set project_name mnv2_depthwise
set project_dir [file normalize "./vivado_project"]
set part xc7a100tcsg324-1

create_project $project_name $project_dir -part $part -force

add_files [file normalize "./rtl/expansion/expansion_unit.v"]
add_files [file normalize "./rtl/depthwise/depthwise_unit.v"]
add_files [file normalize "./rtl/projection/projection_unit.v"]

set_property top expansion_unit [current_fileset]
update_compile_order -fileset sources_1

puts "Created Vivado project: $project_dir/$project_name.xpr"
