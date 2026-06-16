ENTRY(k_load)

SECTIONS {
    . = 0x80000000;
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

    . += 0x2000;
    s_top = .; 
    . += 0x2000;
    isr_s_top = .; 
    . += 0x1000;
    g_top = .;
}
