# Force zicsr extension for RISC-V assembler
CFLAGS += -march=rv32i2p0_m_zicsr -mabi=ilp32 -Wa,-march=rv32i2p0_m_zicsr
ASFLAGS += -march=rv32i2p0_m_zicsr
export CFLAGS
export ASFLAGS
include ../include/generated/variables.mak
include $(SOC_DIRECTORY)/software/common.mak

OBJECTS =  \
	crc16.o    \
	crc32.o    \
	console.o  \
	system.o   \
	progress.o \
	memtest.o  \
	uart.o     \
	spiflash.o \
	i2c.o \
	isr.o

all: libbase.a

libbase.a: $(OBJECTS)
	$(AR) crs libbase.a $(OBJECTS)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

%.o: $(LIBBASE_DIRECTORY)/%.c
	$(compile)

.PHONY: all clean

clean:
	$(RM) $(OBJECTS)
	$(RM) libbase.a .*~ *~
