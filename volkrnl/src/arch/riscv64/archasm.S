.global arch_get_mhartid
.global arch_get_mie
.global arch_get_mepc
.global arch_get_mcause
.global arch_get_mtvec
.global arch_get_mscratch
.global arch_get_mstatus

.global arch_set_mie
.global arch_set_mcause
.global arch_set_mtvec
.global arch_set_mscratch
.global arch_set_mstatus

.extern arch_print_registers
.section .text


arch_get_mhartid:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mhartid

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra



arch_get_mie:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mie

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra


arch_get_mepc:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mepc

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra


arch_get_mcause:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mcause

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra

arch_get_mtvec:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mtvec

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra

arch_get_mscratch:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mscratch

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra

arch_get_mstatus:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrr a0, mstatus

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra



arch_set_mie:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrw mie, a0

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra


arch_set_mepc:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrw mepc, a0

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra


arch_set_mcause:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrw mcause, a0

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra

arch_set_mtvec:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)
    csrw mtvec, a0
    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra


arch_set_mscratch:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrw mscratch, a0

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra

arch_set_mstatus:
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    csrw mstatus, a0

    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    jr ra
