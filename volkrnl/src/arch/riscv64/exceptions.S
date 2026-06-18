.global exception_handler

.extern exception_parser
.section .text




exception_handler:
    addi sp, sp, -16
    sd ra, 8(sp)
    sd s0, 0(sp)
    
    call exception_parser

    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0

    ld ra, 8(sp)
    ld s0, 0(sp)
    addi sp, sp, 16
    mret

