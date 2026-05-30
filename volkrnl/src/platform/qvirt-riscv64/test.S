.global test_function

.extern uart_cprint
.section .text



idk:
    .asciz "Heyo!"


test_function:
    addi sp, sp, -16
    sd ra, 8(sp)
    sd s0, 0(sp)
    la a0, idk
    call uart_cprint

    ld ra, 8(sp)
    ld s0, 0(sp)
    addi sp, sp, 16
    jr ra