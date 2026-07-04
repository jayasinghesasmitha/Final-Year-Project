
# Create Project

create_project -force -name digilent_arty -part xc7a35ticsg324-1L
set_msg_config -id {Common 17-55} -new_severity {Warning}

# Add Sources

read_verilog {/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/proj/mnv2_first/cfu.v}
read_verilog {/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/third_party/python/pythondata_cpu_vexriscv/pythondata_cpu_vexriscv/verilog/VexRiscv_FullCfu.v}
read_verilog {/home/sasmitha-jayasinghe/Documents/github/CFU-Playground/soc/build/digilent_arty.mnv2_first/gateware/digilent_arty.v}

# Add EDIFs


# Add IPs


# Add constraints

read_xdc digilent_arty.xdc
set_property PROCESSING_ORDER EARLY [get_files digilent_arty.xdc]

# Add pre-synthesis commands


# Synthesis

synth_design -directive default -top digilent_arty -part xc7a35ticsg324-1L

# Synthesis report

report_timing_summary -file digilent_arty_timing_synth.rpt
report_utilization -hierarchical -file digilent_arty_utilization_hierarchical_synth.rpt
report_utilization -file digilent_arty_utilization_synth.rpt

# Optimize design

opt_design -directive default

# Add pre-placement commands


# Placement

place_design -directive default

# Placement report

report_utilization -hierarchical -file digilent_arty_utilization_hierarchical_place.rpt
report_utilization -file digilent_arty_utilization_place.rpt
report_io -file digilent_arty_io.rpt
report_control_sets -verbose -file digilent_arty_control_sets.rpt
report_clock_utilization -file digilent_arty_clock_utilization.rpt

# Add pre-routing commands


# Routing

route_design -directive default
phys_opt_design -directive default
write_checkpoint -force digilent_arty_route.dcp

# Routing report

report_timing_summary -no_header -no_detailed_paths
report_route_status -file digilent_arty_route_status.rpt
report_drc -file digilent_arty_drc.rpt
report_timing_summary -datasheet -max_paths 10 -file digilent_arty_timing.rpt
report_power -file digilent_arty_power.rpt
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]

# Bitstream generation

write_bitstream -force digilent_arty.bit 
write_cfgmem -force -format bin -interface spix4 -size 16 -loadbit "up 0x0 digilent_arty.bit" -file digilent_arty.bin

# End

quit