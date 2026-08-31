IVERILOG ?= iverilog
VVP ?= vvp

RTL = \
  ../rtl/memory/ifmap_buffer.v \
  ../rtl/memory/expansion_weight_buffer.v \
  ../rtl/memory/depthwise_weight_buffer.v \
  ../rtl/memory/projection_weight_buffer.v \
  ../rtl/memory/expanded_buffer.v \
  ../rtl/memory/depthwise_output_buffer.v \
  ../rtl/memory/output_buffer.v \
  ../rtl/expansion/expansion_engine.v \
  ../rtl/depthwise/depthwise_engine.v \
  ../rtl/projection/projection_engine.v \
  ../rtl/controller/mnv2_controller.v \
  ../rtl/mnv2_depthwise_top.v

all: phase4c phase5

phase4c:
	$(IVERILOG) -g2012 -Wall -o tb_phase4c_fixed $(RTL) tb_mnv2_depthwise_phase4c_fixed.v
	$(VVP) tb_phase4c_fixed

phase5:
	$(IVERILOG) -g2012 -Wall -o tb_phase5 $(RTL) ../cfu/mnv2_depthwise_cfu.v tb_mnv2_depthwise_phase5_cfu.v
	$(VVP) tb_phase5

clean:
	rm -f tb_phase4c_fixed tb_phase5 *.vcd
