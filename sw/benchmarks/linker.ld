OUTPUT_ARCH("riscv")
ENTRY(_start)
MEMORY {
  ROM (rx)  : ORIGIN = 0x00000000, LENGTH = 16K
  RAM (rwx) : ORIGIN = 0x00004000, LENGTH = 16K
}
SECTIONS {
  .text : { *(.text*) } > ROM
  .rodata : { *(.rodata*) } > ROM
  .data : { *(.data*) } > RAM
  .bss : { *(.bss*) } > RAM
  _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
