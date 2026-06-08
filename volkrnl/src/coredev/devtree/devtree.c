#include <coredev/devtree.h>
#include <rtl/mem.h>
#include <rtl/string.h>
#include <rtl/print.h>

#include <coredev/uart.h>

static uptr base = 0;

void dtree_setup(uptr address){
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

u64 dtree_get_base(){
    return base;
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

void dtree_begin_string_list(FDTStringList* list, uptr address, usize maxSize){
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

void dtree_begin_rmem_list(FDTReservedMemList* list, uptr address, usize maxSize){
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

void dtree_parse(){
    // test parsing
    u64 strucAddr = dtree_get_structure_block_addr();
    u64 strAddr = dtree_get_string_block_addr();
    u64 offset = 0;
    volatile u32* addr = (u32*)(strucAddr + offset);
    while(1){
        rtl_print_hex("Reading from: ", (u64)(addr + offset), TRUE);

        u32 first = rtl_bswap32(addr[offset]);
        if(first == FDT_BEGIN_NODE){
            char* str = (char*)(addr + offset + 1);
            rtl_print("FDT_BEGIN_NODE\n");
            rtl_print(str);
            int len = rtl_get_cstring_len(str);
            rtl_print_dec("len: ", 0, TRUE);
            offset += rtl_align_up(len + 1, 4);
        } else if(first == FDT_PROP) {
            rtl_print("FDT_PROP\n");
            FDTProperties* prop = (FDTProperties*)addr;
            rtl_print_hex("Length: ", rtl_bswap32(prop->len), TRUE);
            char* str = (char*)(strAddr + rtl_bswap32(prop->nameOffset));
            rtl_print(str);
            rtl_print("\n");
            offset++;
        } else if(first == FDT_END_NODE){
            rtl_print("FDT_END_NODE\n");
            offset++;
            break;
        } else {
            offset++;
        }
    }
    rtl_print("Finished parsing main node\n");
}

