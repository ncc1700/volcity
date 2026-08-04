.global plat_entry
.comm stack, 0x10000


plat_entry:
    ldr sp, =stack+0x10000
    bl plat_setup
loop:
    b loop