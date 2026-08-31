ENTRY(_start)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 64K
}

SECTIONS
{
    .text : ALIGN(4)
    {
        *(.text.init)
        *(.text*)
        *(.rodata*)
    } > RAM

    .data : ALIGN(4)
    {
        *(.data*)
    } > RAM

    .bss : ALIGN(4)
    {
        *(.bss*)
        *(COMMON)
    } > RAM

    . = ALIGN(16);
    . += 4096;
    _stack_top = .;
}
