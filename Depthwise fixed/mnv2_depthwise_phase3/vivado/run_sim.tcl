# Example standalone simulation script.
# Run from the repository root after create_project.tcl.

set_property top tb_expansion [get_filesets sim_1]
update_compile_order -fileset sim_1
launch_simulation
run all
