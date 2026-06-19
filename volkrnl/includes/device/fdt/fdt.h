#ifndef DEVDT_H_INCLUDED
#define DEVDT_H_INCLUDED







#include <device/device.h>




typedef struct _FdtHeader {
    u32 magic;
    u32 totalSize;
    u32 dtStructOffset;
    u32 dtStringsOffset;
    u32 memReservOffset;
    u32 version;
    u32 lastCompVersion;
    u32 bootPhysCpuid;
    u32 dtStringSize;
    u32 dtStructSize;
} FdtHeader;

typedef struct _FdtInfo {
    FdtHeader header;
    uptr fdtAddress;
} FdtInfo;


boolean dev_fdt_init(FdtInfo* info, uptr address);
void dev_fdt_print_all_strings(FdtInfo* info);















#endif