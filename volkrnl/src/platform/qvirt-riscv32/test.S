.global test_function

.extern uart_cprint
.section .text



idk:
    .asciz "Heyo!"


test_function:
    addi sp, sp, -16
    sw ra, 8(sp)
    sw s0, 0(sp)
    la a0, idk
    call uart_cprint

    lw ra, 8(sp)
    lw s0, 0(sp)
    addi sp, sp, 16
    jr ra