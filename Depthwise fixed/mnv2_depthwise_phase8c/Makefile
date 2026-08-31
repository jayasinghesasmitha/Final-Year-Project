RISCV ?= riscv32-unknown-elf

.PHONY: all sw renode clean

all: sw

sw:
	$(MAKE) -C sw RISCV=$(RISCV)

renode:
	renode renode/mnv2_depthwise.resc

clean:
	$(MAKE) -C sw clean
