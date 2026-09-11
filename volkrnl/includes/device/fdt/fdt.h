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
    u32* cells;
    usize cellAmount;
    uptr fdtAddress;
} FdtInfo;

typedef struct _FdtProp {
    u32 length;
    u32 nameOffset;
} FdtProp;


boolean fdt_init(FdtInfo* info, uptr address);
const char* fdt_get_string(FdtInfo* info, u32 offset);
void fdt_print_all_strings(FdtInfo* info);
void fdt_print_node(FdtInfo* info, u32 offset);
void fdt_dump(FdtInfo* info);
boolean fdt_find_node(FdtInfo* info, const char* nodeName, u32* offset);
FdtProp* fdt_get_prop_ex(FdtInfo* info, u32 nodeOffset, const char* propName, u32* propOffset);
FdtProp* fdt_get_prop(FdtInfo* info, u32 nodeOffset, const char* propName);
u32 fdt_get_value_from_prop(FdtInfo* info, u32 propOffset);
void fdt_get_array_from_prop(FdtInfo* info, u32 propOffset, uptr* array, usize length);
//const char* fdt_get_string_from_prop(FdtInfo* info, u32 propOffset);









#endif
