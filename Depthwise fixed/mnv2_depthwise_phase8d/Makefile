RISCV_PREFIX ?= riscv32-unknown-elf-

.PHONY: all sw renode clean

all: sw

sw:
	$(MAKE) -C sw CROSS=$(RISCV_PREFIX)

renode: sw
	renode renode/mnv2_depthwise.resc

clean:
	$(MAKE) -C sw clean
	$(MAKE) -C sim clean
