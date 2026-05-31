.section .text


.global k_load
.extern k_entry



k_load:
    la gp, g_top
    la sp, s_top
    csrw satp, 0
    la t0, k_entry
    csrw mepc, t0
    mv a0, a1
    tail k_entry
    