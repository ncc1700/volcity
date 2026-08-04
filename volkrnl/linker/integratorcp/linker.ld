ENTRY(plat_entry)

SECTIONS {
    . = 0x0;
    .text : ALIGN(4K) {
        *(.text)
    }

    .data : ALIGN(4K) {
        *(.data)
    }

    .rodata : ALIGN(4K) {
        *(.data)
    }

    .bss : ALIGN(4K) {
        *(.bss)
    }
}
