#ifndef DEVTREE_H_INCLUDED
#define DEVTREE_H_INCLUDED



#include <types.h>

#define FDT_BEGIN_NODE 0x00000001
#define FDT_END_NODE 0x00000002
#define FDT_PROP 0x00000003
#define FDT_NOP 0x00000004
#define FDT_END 0x00000009

typedef struct _FDTHeader {
    u32 magic;
    u32 totalSize;
    u32 structureOffset;
    u32 stringsOffset;
    u32 memReservOffset;
    u32 version;
    u32 lastCompVersion;
    u32 bootCpuPhysId;
    u32 stringSize;
    u32 structureSize;
} FDTHeader;

typedef struct _FDTReservedMemEntry {
    u64 address;
    u64 size;
} FDTReservedMemEntry;

typedef struct _FDTStringList {
    u64 beginningAddr;
    u32 size;
    u32 maxSize;
    char* string;
} FDTStringList;

typedef struct _FDTReservedMemList {
    FDTReservedMemEntry* rMemEntry;
    u64 beginningAddr;
    u32 size;
    u32 maxSize;
} FDTReservedMemList;

typedef struct _FDTProperties {
    u32 len;
    u32 nameOffset;
} FDTProperties;

void dtree_setup(u64 address);
u64 dtree_get_base();
void dtree_get_header(FDTHeader* header);
u64 dtree_get_structure_block_addr();
u64 dtree_get_string_block_addr();
u64 dtree_get_reserved_mem_block_addr();
void dtree_begin_string_list(FDTStringList* list, u64 address, u64 maxSize);
boolean dtree_next_string_list(FDTStringList* list);
void dtree_begin_rmem_list(FDTReservedMemList* list, u64 address, u64 maxSize);
boolean dtree_next_rmem_list(FDTReservedMemList* list);
void dtree_parse();




#endif