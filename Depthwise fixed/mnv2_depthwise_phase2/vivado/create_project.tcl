set project_name mnv2_depthwise_phase2
set project_dir [file normalize "./vivado_project"]
set part xc7a100tcsg324-1

create_project $project_name $project_dir -part $part -force
add_files [file normalize "./rtl/mnv2_depthwise_cfu.v"]
add_files [file normalize "./cfu/cfu_interface.v"]
add_files [file normalize "./sim/tb_mnv2_depthwise_cfu.v"]

set_property top tb_mnv2_depthwise_cfu [get_filesets sim_1]
update_compile_order -fileset sim_1
puts "Vivado project created."
