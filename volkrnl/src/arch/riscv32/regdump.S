.global arch_print_registers
.extern reg_print_handler


.macro PUSH_REG_TO_STACK
    sw ra, 0(sp)
    sw sp, 8(sp)
    sw gp, 16(sp)
    sw tp, 24(sp)
    sw t0, 32(sp)
    sw t1, 40(sp)
    sw t2, 48(sp)
    sw t3, 56(sp)
    sw t4, 64(sp)
    sw t5, 72(sp)
    sw t6, 80(sp)
    sw fp, 88(sp)
    sw s1, 96(sp)
    sw a0, 104(sp)
    sw a1, 112(sp)
    sw a2, 120(sp)
    sw a3, 128(sp)
    sw a4, 136(sp)
    sw a5, 144(sp)
    sw a6, 152(sp)
    sw a7, 160(sp)
    sw s2, 168(sp)
    sw s3, 176(sp)
    sw s4, 184(sp)
    sw s5, 192(sp)
    sw s6, 200(sp)
    sw s7, 208(sp)
    sw s8, 216(sp)
    sw s9, 224(sp)
    sw s10, 232(sp)
    sw s11, 240(sp)
    sw s0, 248(sp)
.endmacro

.macro POP_REG_FROM_STACK
    lw ra, 0(sp)
    lw sp, 8(sp)
    lw gp, 16(sp)
    lw tp, 24(sp)
    lw t0, 32(sp)
    lw t1, 40(sp)
    lw t2, 48(sp)
    lw t3, 56(sp)
    lw t4, 64(sp)
    lw t5, 72(sp)
    lw t6, 80(sp)
    lw fp, 88(sp)
    lw s1, 96(sp)
    lw a0, 104(sp)
    lw a1, 112(sp)
    lw a2, 120(sp)
    lw a3, 128(sp)
    lw a4, 136(sp)
    lw a5, 144(sp)
    lw a6, 152(sp)
    lw a7, 160(sp)
    lw s2, 168(sp)
    lw s3, 176(sp)
    lw s4, 184(sp)
    lw s5, 192(sp)
    lw s6, 200(sp)
    lw s7, 208(sp)
    lw s8, 216(sp)
    lw s9, 224(sp)
    lw s10, 232(sp)
    lw s11, 240(sp)
    lw s0, 248(sp)
.endmacro




arch_print_registers:
    addi sp, sp, -272
    PUSH_REG_TO_STACK
    mv a0, sp
    call reg_print_handler
    POP_REG_FROM_STACK
    addi sp, sp, 272
    jr ra