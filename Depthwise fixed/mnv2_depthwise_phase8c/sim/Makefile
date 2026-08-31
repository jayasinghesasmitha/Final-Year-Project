IVERILOG=iverilog
VVP=vvp
TARGET=tb_phase8c
RTL=../rtl/mnv2_depthwise_top.v ../rtl/mnv2_depthwise_cfu.v
TB=tb_phase8c_cfu.v

all: test
test:
	$(IVERILOG) -g2012 -Wall -o $(TARGET) $(RTL) $(TB)
	$(VVP) $(TARGET)
wave: test
	gtkwave mnv2_depthwise_phase8c.vcd
clean:
	rm -f $(TARGET) *.vcd
