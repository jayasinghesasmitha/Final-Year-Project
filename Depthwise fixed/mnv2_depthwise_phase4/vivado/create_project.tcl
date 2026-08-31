set project_name mnv2_depthwise_phase4
set project_dir [file normalize "./vivado_project"]
set part xc7a100tcsg324-1

create_project $project_name $project_dir -part $part -force

add_files [file normalize "./rtl/memory/ifmap_buffer.v"]
add_files [file normalize "./rtl/memory/expansion_weight_buffer.v"]
add_files [file normalize "./rtl/memory/depthwise_weight_buffer.v"]
add_files [file normalize "./rtl/memory/projection_weight_buffer.v"]
add_files [file normalize "./rtl/memory/output_buffer.v"]
add_files [file normalize "./rtl/expansion/expansion_engine.v"]
add_files [file normalize "./rtl/depthwise/depthwise_engine.v"]
add_files [file normalize "./rtl/projection/projection_engine.v"]
add_files [file normalize "./rtl/controller/mnv2_controller.v"]
add_files [file normalize "./rtl/mnv2_depthwise_top.v"]
add_files [file normalize "./sim/tb_mnv2_depthwise_phase4.v"]

set_property top tb_mnv2_depthwise_phase4 [get_filesets sim_1]
update_compile_order -fileset sim_1
puts "Phase 4 Vivado project created."
