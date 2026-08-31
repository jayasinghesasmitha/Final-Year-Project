# Phase 8D keeps the verified RTL regression separate.
# Copy the verified Phase 8B/8C RTL into ../rtl/ if you want to run it here.

IVERILOG=iverilog
VVP=vvp
TARGET=tb_phase8d
RTL=../rtl/mnv2_depthwise_top.v ../rtl/mnv2_depthwise_cfu.v
TB=tb_phase8d_cfu.v

.PHONY: test clean wave
test:
	$(IVERILOG) -g2012 -Wall -o $(TARGET) $(RTL) $(TB)
	$(VVP) $(TARGET)

clean:
	rm -f $(TARGET) *.vcd

wave: test
	gtkwave mnv2_depthwise_phase8d.vcd
