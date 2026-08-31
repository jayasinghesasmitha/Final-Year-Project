RTL=../rtl/mnv2_depthwise_top.v
CFU=../cfu/mnv2_depthwise_cfu.v
TB=tb_phase7_cfu.v
OUT=tb_phase7

all: test

test:
	iverilog -g2012 -Wall -o $(OUT) $(RTL) $(CFU) $(TB)
	vvp $(OUT)

wave:
	gtkwave mnv2_depthwise_phase7.vcd

clean:
	rm -f $(OUT) *.vcd
