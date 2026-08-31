IVERILOG=iverilog
VVP=vvp
TARGET=tb_phase8b
RTL=../rtl/mnv2_depthwise_top.v ../rtl/mnv2_depthwise_cfu.v
TB=tb_phase8b_cfu.v

.PHONY: all test clean wave
all: test
test:
	$(IVERILOG) -g2012 -Wall -o $(TARGET) $(RTL) $(TB)
	$(VVP) $(TARGET)
wave: test
	gtkwave mnv2_depthwise_phase8b.vcd
clean:
	rm -f $(TARGET) *.vcd
