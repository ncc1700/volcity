#include <arch/arch.h>
#include <arch/arm64/archdef.h>
#include <rtl/print.h>









void reg_dump_handler(RegisterState* state){
    rtl_print_hex("X0: ", state->x0, FALSE);
    rtl_print_hex("  X1: ", state->x1, TRUE);
    rtl_print_hex("X2: ", state->x2, FALSE);
    rtl_print_hex("  X3: ", state->x3, TRUE);
    rtl_print_hex("X4: ", state->x4, FALSE);
    rtl_print_hex("  X5: ", state->x5, TRUE);
    rtl_print_hex("X6: ", state->x6, FALSE);
    rtl_print_hex("  X7: ", state->x7, TRUE);
    rtl_print_hex("X8: ", state->x8, FALSE);
    rtl_print_hex("  X9: ", state->x9, TRUE);

    rtl_print_hex("X10: ", state->x10, FALSE);
    rtl_print_hex("  X11: ", state->x11, TRUE);
    rtl_print_hex("X12: ", state->x12, FALSE);
    rtl_print_hex("  X13: ", state->x13, TRUE);
    rtl_print_hex("X14: ", state->x14, FALSE);
    rtl_print_hex("  X15: ", state->x15, TRUE);
    rtl_print_hex("X16: ", state->x16, FALSE);
    rtl_print_hex("  X17: ", state->x17, TRUE);
    rtl_print_hex("X18: ", state->x18, FALSE);
    rtl_print_hex("  X19: ", state->x19, TRUE);

    rtl_print_hex("X20: ", state->x20, FALSE);
    rtl_print_hex("  X21: ", state->x21, TRUE);
    rtl_print_hex("X22: ", state->x22, FALSE);
    rtl_print_hex("  X23: ", state->x23, TRUE);
    rtl_print_hex("X24: ", state->x24, FALSE);
    rtl_print_hex("  X52: ", state->x25, TRUE);
    rtl_print_hex("X26: ", state->x26, FALSE);
    rtl_print_hex("  X27: ", state->x27, TRUE);
    rtl_print_hex("X28: ", state->x28, FALSE);
    rtl_print_hex("  X29: ", state->x29, TRUE);

    rtl_print_hex("X30: ", state->x30, FALSE);
    rtl_print_hex("  ESR: ", state->esr, TRUE);
    rtl_print_hex("FAR: ", state->far, FALSE);
    rtl_print_hex("  SP: ", state->sp, TRUE);
}