RISCV ?= riscv32-unknown-elf
CC = $(RISCV)-gcc
OBJCOPY = $(RISCV)-objcopy

CFLAGS = -march=rv32im_zicsr_zifencei -mabi=ilp32 -O2 -ffreestanding -fno-builtin -nostdlib -nostartfiles
LDFLAGS = -T linker.ld -nostdlib -nostartfiles

ELF = mnv2_depthwise.elf
BIN = mnv2_depthwise.bin

all: $(ELF) $(BIN)

$(ELF): startup.S main.c mnv2_depthwise.c mnv2_depthwise.h cfu_instruction.h linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ startup.S main.c mnv2_depthwise.c

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(ELF) $(BIN)
