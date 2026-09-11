#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED







#include <types.h>
#include <memory/memory.h>

typedef struct _InitRdInfo {
    uptr base;
    usize size;
} InitRdInfo;

void kern_entry(MemoryMap* memMap, InitRdInfo* info);
[[noreturn]] void kern_panic(const char* reason);
void kern_parse_tar(uptr* address);











#endif
