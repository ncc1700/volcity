.global arch_print_registers
.extern reg_print_handler


.macro PUSH_REG_TO_STACK
    stp x0, x1, [sp, #0]    
    stp x2, x3, [sp, #16]  
    stp x4, x5, [sp, #32]  
    stp x6, x7, [sp, #48]    
    stp x8, x9, [sp, #64]  
    stp x10, x11, [sp, #80]  
    stp x12, x13, [sp, #96]  
    stp x14, x15, [sp, #112]  
    stp x16, x17, [sp, #128]    
    stp x18, x19, [sp, #144]  
    stp x20, x21, [sp, #160]  
    stp x22, x23, [sp, #176]  
    stp x24, x25, [sp, #192]  
    stp x26, x27, [sp, #208]    
    stp x28, x29, [sp, #224]  
    mrs x0, ESR_EL1
    mrs x1, FAR_EL1
    stp x30, x0, [sp, #240]  
    mov x0, sp
    stp x1, x0, [sp, #256]  // ???
    mov x0, sp
.endmacro

.macro POP_REG_FROM_STACK
    ldp x0, x1, [sp, #0]    
    ldp x2, x3, [sp, #16]  
    ldp x4, x5, [sp, #32]  
    ldp x6, x7, [sp, #48]    
    ldp x8, x9, [sp, #64]  
    ldp x10, x11, [sp, #80]  
    ldp x12, x13, [sp, #96]  
    ldp x14, x15, [sp, #112]  
    ldp x16, x17, [sp, #128]    
    ldp x18, x19, [sp, #144]  
    ldp x20, x21, [sp, #160]  
    ldp x22, x23, [sp, #176]  
    ldp x24, x25, [sp, #192]  
    ldp x26, x27, [sp, #208]    
    ldp x28, x29, [sp, #224]  
    ldp x30, x0, [sp, #240]  
    msr ESR_EL1, x0 
    ldp x1, x0, [sp, #256] 
    msr FAR_EL1, x1
.endmacro




arch_print_registers:
    sub sp, sp, #256
    PUSH_REG_TO_STACK
    b reg_print_handler
    POP_REG_FROM_STACK
    add sp, sp, #256
    ret