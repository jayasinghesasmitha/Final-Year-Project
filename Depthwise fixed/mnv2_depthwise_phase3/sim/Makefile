IVERILOG ?= iverilog
VVP ?= vvp

all: test

test:
	$(IVERILOG) -g2012 -Wall -o tb_cfu \
	  ../rtl/mnv2_depthwise_cfu.v \
	  tb_mnv2_depthwise_cfu.v
	$(VVP) tb_cfu

clean:
	rm -f tb_cfu *.vcd
