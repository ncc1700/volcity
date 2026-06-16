.global arch_switch_context





.macro SAVE_CONTEXT base
    sd ra, 0(\base)
    sd sp, 8(\base)
    sd gp, 16(\base)
    sd tp, 24(\base)
    // sd t0, 32(\base)
    // sd t1, 40(\base)
    sd t2, 48(\base)
    sd t3, 56(\base)
    sd t4, 64(\base)
    sd t5, 72(\base)
    sd t6, 80(\base)
    sd fp, 88(\base)
    sd s1, 96(\base)
    sd a0, 104(\base)
    sd a1, 112(\base)
    sd a2, 120(\base)
    sd a3, 128(\base)
    sd a4, 136(\base)
    sd a5, 144(\base)
    sd a6, 152(\base)
    sd a7, 160(\base)
    sd s2, 168(\base)
    sd s3, 176(\base)
    sd s4, 184(\base)
    sd s5, 192(\base)
    sd s6, 200(\base)
    sd s7, 208(\base)
    sd s8, 216(\base)
    sd s9, 224(\base)
    sd s10, 232(\base)
    sd s11, 240(\base)
    sd s0, 248(\base)
.endmacro

.macro LOAD_CONTEXT base
    ld ra, 0(\base)
    ld sp, 8(\base)
    ld gp, 16(\base)
    ld tp, 24(\base)
    // ld t0, 32(\base)
    // ld t1, 40(\base)
    ld t2, 48(\base)
    ld t3, 56(\base)
    ld t4, 64(\base)
    ld t5, 72(\base)
    ld t6, 80(\base)
    ld fp, 88(\base)
    ld s1, 96(\base)
    ld a0, 104(\base)
    ld a1, 112(\base)
    ld a2, 120(\base)
    ld a3, 128(\base)
    ld a4, 136(\base)
    ld a5, 144(\base)
    ld a6, 152(\base)
    ld a7, 160(\base)
    ld s2, 168(\base)
    ld s3, 176(\base)
    ld s4, 184(\base)
    ld s5, 192(\base)
    ld s6, 200(\base)
    ld s7, 208(\base)
    ld s8, 216(\base)
    ld s9, 224(\base)
    ld s10, 232(\base)
    ld s11, 240(\base)
    ld s0, 248(\base)
.endmacro



arch_switch_context:
    mv t0, a0
    mv t1, a1
    SAVE_CONTEXT t0
    LOAD_CONTEXT t1
    jr ra