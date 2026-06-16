.section .text


.global k_load
.extern k_entry



k_load:
    la gp, g_top
    la sp, s_top
    la t0, isr_s_top
    csrw mscratch, t0
    csrw satp, 0
    la t0, k_entry
    csrw mepc, t0

    csrr t1, mie
    li t2, 0x800
    or t1, t1, t2
    csrw mie, t1
    
    csrr t1, mstatus
    ori t1, t1, 0x8
    csrw mstatus, t1

    mv a0, a1
    j k_entry
loop:
    j loop
    