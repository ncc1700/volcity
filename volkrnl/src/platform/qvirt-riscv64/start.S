.section .text


.global plat_entry
.extern plat_setup
.extern exception_handler


plat_entry:
    la gp, g_top
    la sp, s_top
    csrw satp, 0
    la t0, plat_setup
    csrw mepc, t0    
    mv a0, a1
    la a1, k_end
    tail plat_setup
    
