CROSS ?= riscv64-unknown-elf-
CC := $(CROSS)gcc
OBJCOPY := $(CROSS)objcopy
CFLAGS := -march=rv32im_zicsr -mabi=ilp32 -O2 -ffreestanding -fno-builtin -nostdlib -nostartfiles
LDFLAGS := -T linker.ld -nostdlib -nostartfiles -Wl,--gc-sections

TARGET := mnv2_depthwise.elf

all: $(TARGET)

$(TARGET): startup.S main.c mnv2_depthwise.c mnv2_depthwise.h cfu_instruction.h linker.ld
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ startup.S mnv2_depthwise.c main.c

bin: $(TARGET)
	$(OBJCOPY) -O binary $< mnv2_depthwise.bin

clean:
	rm -f $(TARGET) mnv2_depthwise.bin
