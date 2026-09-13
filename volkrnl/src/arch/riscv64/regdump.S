.global arch_dump_and_print_registers
.global arch_dump_registers
.extern arch_print_registers


.macro PUSH_REG x
    sd ra, 0(\x)
    sd sp, 8(\x)
    sd gp, 16(\x)
    sd tp, 24(\x)
    sd t0, 32(\x)
    sd t1, 40(\x)
    sd t2, 48(\x)
    sd t3, 56(\x)
    sd t4, 64(\x)
    sd t5, 72(\x)
    sd t6, 80(\x)
    sd fp, 88(\x)
    sd s1, 96(\x)
    sd a0, 104(\x)
    sd a1, 112(\x)
    sd a2, 120(\x)
    sd a3, 128(\x)
    sd a4, 136(\x)
    sd a5, 144(\x)
    sd a6, 152(\x)
    sd a7, 160(\x)
    sd s2, 168(\x)
    sd s3, 176(\x)
    sd s4, 184(\x)
    sd s5, 192(\x)
    sd s6, 200(\x)
    sd s7, 208(\x)
    sd s8, 216(\x)
    sd s9, 224(\x)
    sd s10, 232(\x)
    sd s11, 240(\x)
    sd s0, 248(\x)
.endmacro

.macro POP_REG x
    ld ra, 0(\x)
    ld sp, 8(\x)
    ld gp, 16(\x)
    ld tp, 24(\x)
    ld t0, 32(\x)
    ld t1, 40(\x)
    ld t2, 48(\x)
    ld t3, 56(\x)
    ld t4, 64(\x)
    ld t5, 72(\x)
    ld t6, 80(\x)
    ld fp, 88(\x)
    ld s1, 96(\x)
    ld a0, 104(\x)
    ld a1, 112(\x)
    ld a2, 120(\x)
    ld a3, 128(\x)
    ld a4, 136(\x)
    ld a5, 144(\x)
    ld a6, 152(\x)
    ld a7, 160(\x)
    ld s2, 168(\x)
    ld s3, 176(\x)
    ld s4, 184(\x)
    ld s5, 192(\x)
    ld s6, 200(\x)
    ld s7, 208(\x)
    ld s8, 216(\x)
    ld s9, 224(\x)
    ld s10, 232(\x)
    ld s11, 240(\x)
    ld s0, 248(\x)
.endmacro




arch_dump_and_print_registers:
    addi sp, sp, -272
    PUSH_REG sp
    mv a0, sp
    call arch_print_registers
    POP_REG sp
    addi sp, sp, 272
    jr ra

arch_dump_registers:
    addi sp, sp, -16
    PUSH_REG a0
    addi sp, sp, 16
    jr ra

arch_load_registers:
    addi sp, sp, -16
    POP_REG a0
    addi sp, sp, 16
    jr ra
