#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED







#include <types.h>



typedef enum _MemoryType {
    MEM_TYPE_USABLE,
    MEM_TYPE_UNUSABLE,
    MEM_TYPE_MMIO,
    MEM_TYPE_KERNEL
} MemoryType;

typedef struct _MemoryEntry {
    uptr base;
    uptr size;
    MemoryType type;
} MemoryEntry;

typedef struct _Arena {
    uptr base;
    uptr size;
} Arena;

typedef struct _MemoryMap {
    MemoryEntry* entries;
    usize amount;
    usize sizeOfMemory;
} MemoryMap;

boolean mem_setup_pmm(MemoryMap* memMap);
void* mem_allocate_page();
void* mem_allocate_pages(usize amountOfPages);
boolean mem_free_page(void* address);
boolean mem_free_pages(void* address, usize amountOfPages);

#endif
