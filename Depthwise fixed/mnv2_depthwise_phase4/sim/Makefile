IVERILOG ?= iverilog
VVP ?= vvp

RTL = \
  ../rtl/memory/ifmap_buffer.v \
  ../rtl/memory/expansion_weight_buffer.v \
  ../rtl/memory/depthwise_weight_buffer.v \
  ../rtl/memory/projection_weight_buffer.v \
  ../rtl/memory/output_buffer.v \
  ../rtl/expansion/expansion_engine.v \
  ../rtl/depthwise/depthwise_engine.v \
  ../rtl/projection/projection_engine.v \
  ../rtl/controller/mnv2_controller.v \
  ../rtl/mnv2_depthwise_top.v

all: test

test:
	$(IVERILOG) -g2012 -Wall -o tb_phase4 $(RTL) tb_mnv2_depthwise_phase4.v
	$(VVP) tb_phase4

clean:
	rm -f tb_phase4 *.vcd
