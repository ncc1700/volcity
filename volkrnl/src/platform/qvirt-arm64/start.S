
.global k_load





k_load:
    ldr x1, =s_top
    mov sp, x1
    bl k_entry
loop:
    b loop // infinite loop