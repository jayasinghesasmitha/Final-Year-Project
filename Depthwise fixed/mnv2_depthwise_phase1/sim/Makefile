IVERILOG ?= iverilog
VVP ?= vvp

RTL_EXP = ../rtl/expansion/expansion_unit.v
RTL_DW  = ../rtl/depthwise/depthwise_unit.v
RTL_PROJ = ../rtl/projection/projection_unit.v

.PHONY: all test clean

all: test

test: test_expansion test_depthwise test_projection
	@echo "All Phase 1 RTL tests passed."

test_expansion:
	$(IVERILOG) -g2012 -Wall -o tb_expansion $(RTL_EXP) tb_expansion.v
	$(VVP) tb_expansion

test_depthwise:
	$(IVERILOG) -g2012 -Wall -o tb_depthwise $(RTL_DW) tb_depthwise.v
	$(VVP) tb_depthwise

test_projection:
	$(IVERILOG) -g2012 -Wall -o tb_projection $(RTL_PROJ) tb_projection.v
	$(VVP) tb_projection

clean:
	rm -f tb_expansion tb_depthwise tb_projection *.vcd
