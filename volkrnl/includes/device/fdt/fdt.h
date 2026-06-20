#ifndef DEVDT_H_INCLUDED
#define DEVDT_H_INCLUDED







#include <device/device.h>



#define FDT_BEGIN_NODE 0x00000001
#define FDT_END_NODE 0x00000002
#define FDT_PROP 0x00000003
#define FDT_NOP 0x00000004
#define FDT_END 0x00000009
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

typedef struct _FdtNode {
    uptr offset;
} FdtNode;

typedef struct _FdtProp {
    u32 length;
    u32 nameOffset;
} FdtProp;


boolean dev_fdt_init(FdtInfo* info, uptr address);
const char* dev_fdt_get_string(FdtInfo* info, u32 offset);
void dev_fdt_print_all_strings(FdtInfo* info);
void dev_fdt_dump(FdtInfo* info);














#endif