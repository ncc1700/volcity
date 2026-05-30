.global arch_print_registers
.extern reg_print_handler


.macro PUSH_REG_TO_STACK
    sd ra, 0(sp)
    sd sp, 8(sp)
    sd gp, 16(sp)
    sd tp, 24(sp)
    sd t0, 32(sp)
    sd t1, 40(sp)
    sd t2, 48(sp)
    sd t3, 56(sp)
    sd t4, 64(sp)
    sd t5, 72(sp)
    sd t6, 80(sp)
    sd fp, 88(sp)
    sd s1, 96(sp)
    sd a0, 104(sp)
    sd a1, 112(sp)
    sd a2, 120(sp)
    sd a3, 128(sp)
    sd a4, 136(sp)
    sd a5, 144(sp)
    sd a6, 152(sp)
    sd a7, 160(sp)
    sd s2, 168(sp)
    sd s3, 176(sp)
    sd s4, 184(sp)
    sd s5, 192(sp)
    sd s6, 200(sp)
    sd s7, 208(sp)
    sd s8, 216(sp)
    sd s9, 224(sp)
    sd s10, 232(sp)
    sd s11, 240(sp)
    sd s0, 248(sp)
.endmacro

.macro POP_REG_FROM_STACK
    ld ra, 0(sp)
    ld sp, 8(sp)
    ld gp, 16(sp)
    ld tp, 24(sp)
    ld t0, 32(sp)
    ld t1, 40(sp)
    ld t2, 48(sp)
    ld t3, 56(sp)
    ld t4, 64(sp)
    ld t5, 72(sp)
    ld t6, 80(sp)
    ld fp, 88(sp)
    ld s1, 96(sp)
    ld a0, 104(sp)
    ld a1, 112(sp)
    ld a2, 120(sp)
    ld a3, 128(sp)
    ld a4, 136(sp)
    ld a5, 144(sp)
    ld a6, 152(sp)
    ld a7, 160(sp)
    ld s2, 168(sp)
    ld s3, 176(sp)
    ld s4, 184(sp)
    ld s5, 192(sp)
    ld s6, 200(sp)
    ld s7, 208(sp)
    ld s8, 216(sp)
    ld s9, 224(sp)
    ld s10, 232(sp)
    ld s11, 240(sp)
    ld s0, 248(sp)
.endmacro




arch_print_registers:
    addi sp, sp, -256
    PUSH_REG_TO_STACK

    //call reg_print_handler
    
    POP_REG_FROM_STACK
    addi sp, sp, 256
    jr ra