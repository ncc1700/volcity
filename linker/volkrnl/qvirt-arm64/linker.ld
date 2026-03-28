ENTRY(k_load)

SECTIONS {
    . = 0x40100000;
    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }

    . = ALIGN(16);
    . += 0x2000;
    s_top = .;  
}