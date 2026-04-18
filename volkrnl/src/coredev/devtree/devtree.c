#include <coredev/devtree.h>
#include <rtl/mem.h>
#include <rtl/string.h>

static u64 base = 0;

void dtree_setup(u64 address){
    base = address;
}

void dtree_get_header(FDTHeader* header){
    FDTHeader* beHeader = (FDTHeader*)base;

    header->magic = rtl_bswap32(beHeader->magic);
    header->totalSize = rtl_bswap32(beHeader->totalSize);
    header->structureOffset = rtl_bswap32(beHeader->structureOffset);
    header->stringsOffset = rtl_bswap32(beHeader->stringsOffset);
    header->memReservOffset = rtl_bswap32(beHeader->memReservOffset);
    header->version = rtl_bswap32(beHeader->version);
    header->lastCompVersion = rtl_bswap32(beHeader->lastCompVersion);
    header->bootCpuPhysId = rtl_bswap32(beHeader->bootCpuPhysId);
    header->stringSize = rtl_bswap32(beHeader->stringSize);
    header->structureSize = rtl_bswap32(beHeader->structureSize);
}

u64 dtree_get_structure_block_addr(){
    FDTHeader header = {0};
    dtree_get_header(&header);
    return base + header.structureOffset;
}


u64 dtree_get_string_block_addr(){
    FDTHeader header = {0};
    dtree_get_header(&header);
    return base + header.stringsOffset;
}

u64 dtree_get_reserved_mem_block_addr(){
    FDTHeader header = {0};
    dtree_get_header(&header);
    return base + header.memReservOffset;
}

void dtree_begin_string_list(FDTStringList* list, u64 address, u64 maxSize){
    list->beginningAddr = address;
    list->string = (char*)list->beginningAddr;
    list->size = rtl_get_cstring_len(list->string) + 1;
    list->maxSize = maxSize;
}

boolean dtree_next_string_list(FDTStringList* list){
    if(list->size >= list->maxSize){
        return FALSE;
    }
    list->string = (char*)(list->beginningAddr + list->size);
    list->size += rtl_get_cstring_len(list->string) + 1;
    return TRUE;
}

void dtree_begin_rmem_list(FDTReservedMemList* list, u64 address, u64 maxSize){
    list->beginningAddr = address;
    list->rMemEntry = (FDTReservedMemEntry*)list->beginningAddr;
    list->size = sizeof(FDTReservedMemEntry);
    list->maxSize = maxSize;
}

boolean dtree_next_rmem_list(FDTReservedMemList* list){
    if(list->size >= list->maxSize){
        return FALSE;
    }
    list->rMemEntry = (FDTReservedMemEntry*)(list->beginningAddr + list->size);
    list->size += sizeof(FDTReservedMemEntry);
    return TRUE;
}

