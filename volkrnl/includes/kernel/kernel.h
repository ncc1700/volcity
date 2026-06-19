#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED







#include <types.h>





[[noreturn]] void kern_panic(const char* reason);
void kern_begin_sched();












#endif