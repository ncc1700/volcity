
.global k_load





k_load:
    mov x2, x0
    ldr x1, =s_top
    mov sp, x1
    mov x0, x2
    bl k_entry
loop:
    b loop // infinite loop