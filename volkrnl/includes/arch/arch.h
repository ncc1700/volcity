#ifndef ARCH_H_INCLUDED
#define ARCH_H_INCLUDED







#include <types.h>





void arch_setup();
void arch_print_registers();
void arch_halt();
uptr arch_get_current_core();






#endif