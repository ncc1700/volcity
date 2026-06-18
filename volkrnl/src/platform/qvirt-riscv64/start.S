.section .text


.global plat_entry
.extern kern_entry



plat_entry:
    la gp, g_top
    la sp, s_top
    csrw satp, 0
    la t0, kern_entry
    csrw mepc, t0
    mv a0, a1
    tail kern_entry
    