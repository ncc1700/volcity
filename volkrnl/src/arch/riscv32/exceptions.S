.global arch_setup_exceptions
//.extern core_panic
.extern exception_parser
.extern uart_cprint
.section .text


string:
    .asciz "?"


exception_handler:
    addi sp, sp, -16
    sw ra, 8(sp)
    sw s0, 0(sp)
    csrr a0, mcause
    csrr a1, mepc
    csrr a2, scause
    call exception_parser

    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0
    lw ra, 8(sp)
    lw s0, 0(sp)
    addi sp, sp, 16
    jr ra


arch_setup_exceptions:
    addi sp, sp, -16
    sw ra, 0(sp)
    sw s0, 8(sp)

    la t6, exception_handler
    csrw mtvec, t6

    lw ra, 0(sp)
    lw s0, 8(sp)
    addi sp, sp, 16
    jr ra



