#ifndef KERNEL_H_INCLUDED
#define KERNEL_H_INCLUDED







#include <types.h>
#include <memory/memory.h>

typedef struct _InitRdInfo {
    uptr base;
    usize size;
} InitRdInfo;

volatile typedef struct _TarHeader {
    u8 fileName[100];
    u64 mode;
    u64 oUserId;
    u64 gUserId;
    u8 fileSize[12];
    u8 lastModificationDate[12];
    u64 hrChecksum;
    u8 typeFlag;
    u8 linkedFile[100];
    u8 uStarMagic[6];
    u8 uStarVer[2];
    u8 oUserName[32];
    u8 oGroupName[32];
    u64 devMajor;
    u64 devMinor;
    u8 fileNamePrefix[155];
    u8 padding[12];
} __attribute__((packed)) TarHeader;

void kern_entry(MemoryMap* memMap, InitRdInfo* info);
[[noreturn]] void kern_panic(const char* reason);
void kern_begin_sched();
void kern_parse_tar(uptr* address);











#endif
