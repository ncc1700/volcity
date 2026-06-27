#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED







#include <types.h>

typedef enum _MemoryType {
    MEM_TYPE_USABLE,
    MEM_TYPE_UNUSABLE
} MemoryType;

typedef struct _MemoryEntry {
    uptr base;
    uptr size;
    MemoryType type;
} MemoryEntry;

typedef struct _MemoryMap {
    MemoryEntry* entries;
    usize amount;
    usize sizeOfMemory;
} MemoryMap;













#endif
