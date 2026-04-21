.global arch_setup_exceptions


.extern unknown_exception
.extern error_exception


arch_setup_exceptions:
    sub sp, sp, #16


    ldr x10, =exception_vector
    msr VBAR_EL1, x10

    add sp, sp,  #16
    ret




exception_vector:
    b unknown_exception // sync exception (EL0)
.balign 0x80
    b unknown_exception // IRQ exception (EL0)
.balign 0x80
    b unknown_exception // FIQ exception (EL0)
.balign 0x80
    b unknown_exception // SError exception (EL0)
.balign 0x80
    b error_exception // sync exception (current EL)
.balign 0x80
    b unknown_exception // IRQ exception (current EL)
.balign 0x80
    b unknown_exception // FIQ exception (current EL)
.balign 0x80
    b unknown_exception // SError exception (current EL)
// the rest is for lower ELs from the one we are on
// in the same order
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions
.balign 0x80
    b unknown_exception // IRQ exceptions 
