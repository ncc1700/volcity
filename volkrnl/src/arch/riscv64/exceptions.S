.global arch_setup_exceptions
//.extern core_panic
.extern exception_parser
.section .text




exception_handler:
    addi sp, sp, -16
    sd ra, 8(sp)
    sd s0, 0(sp)
    csrr a0, mcause
    csrr a1, mepc
    csrr a2, scause
    call exception_parser

    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0
    ld ra, 8(sp)
    ld s0, 0(sp)
    addi sp, sp, 16
    jr ra


arch_setup_exceptions:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    la t6, exception_handler
    csrw mtvec, t6

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra



