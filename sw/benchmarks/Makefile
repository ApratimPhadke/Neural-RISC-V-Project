# Makefile for RISC-V benchmark compilation
RISCV_PREFIX ?= riscv32-unknown-elf-
CC = $(RISCV_PREFIX)gcc
OBJCOPY = $(RISCV_PREFIX)objcopy
OBJDUMP = $(RISCV_PREFIX)objdump

CFLAGS = -march=rv32i -mabi=ilp32 -static -nostdlib -nostartfiles -O2 -g
LDFLAGS = -T linker.ld

PROGRAMS = neural_benchmark

all: $(PROGRAMS:%=%.hex) $(PROGRAMS:%=%.bin) $(PROGRAMS:%=%.lst)

# Added -lgcc to link the GCC helper library for functions like modulo
%.elf: %.c startup.s
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -lgcc

%.hex: %.elf
	$(OBJCOPY) -O verilog $< $@

%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.lst: %.elf
	$(OBJDUMP) -D $< > $@

clean:
	rm -f *.o *.elf *.hex *.bin *.lst *.map

.PHONY: all clean
