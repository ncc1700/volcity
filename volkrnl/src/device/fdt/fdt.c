#include <device/fdt/fdt.h>
#include <rtl/mem.h>
#include <rtl/print.h>
#include <rtl/string.h>






boolean dev_fdt_init(FdtInfo* info, uptr address){
    FdtHeader* initial = (FdtHeader*)address;
    info->fdtAddress = address;
    info->header.magic = rtl_bswap32(initial->magic);
    if(info->header.magic != 0xd00dfeed){
        rtl_printf("header magic is not 0xd00dfeed, its 0x%x\n", info->header.magic);
        return FALSE;
    }
    info->header.totalSize = rtl_bswap32(initial->totalSize);
    info->header.dtStructOffset = rtl_bswap32(initial->dtStructOffset);
    info->header.dtStringsOffset = rtl_bswap32(initial->dtStringsOffset);
    info->header.memReservOffset = rtl_bswap32(initial->memReservOffset);
    info->header.version = rtl_bswap32(initial->version);
    info->header.lastCompVersion = rtl_bswap32(initial->lastCompVersion);
    info->header.bootPhysCpuid = rtl_bswap32(initial->bootPhysCpuid);
    info->header.dtStringSize = rtl_bswap32(initial->dtStringSize);
    info->header.dtStructSize = rtl_bswap32(initial->dtStructSize);
    return TRUE;
}


const char* dev_fdt_get_string(FdtInfo* info, u32 offset){
    if(offset >= info->header.dtStringSize){
        return "invalid";
    }
    uptr address = info->fdtAddress + info->header.dtStringsOffset;
    const char* string = (const char*)(address + offset);
    return string;
}

void dev_fdt_print_all_strings(FdtInfo* info){
    uptr address = info->fdtAddress + info->header.dtStringsOffset;
    uptr offset = 0;
    const char* style = "------------------------------------------------------------\n";
    rtl_print("\n");
    rtl_print(style);
    rtl_print("printing fdt string table\n");
    rtl_print(style);
    while(offset < info->header.dtStringSize){
        const char* string = dev_fdt_get_string(info, offset);
        rtl_print(string);
        rtl_print("\n"); 
        usize len = rtl_get_cstring_len(string);
        offset += len + 1;   
           
    }
    rtl_print(style);
    rtl_print("\n");
}


// absoloutly horrendous code

u32 dev_fdt_print_node(FdtInfo* info, u32* cells, u32 cellSize, u32 offset){
    while(offset < cellSize){
        u32 value = rtl_bswap32(cells[offset]);
        switch(value){
            case FDT_BEGIN_NODE:{
                rtl_print("FDT_BEGIN_NODE\n");
                const char* name = (const char*)(cells + offset + 1);
                rtl_print(name);
                rtl_print("\n");
                usize len = rtl_get_cstring_len(name);
                offset += (rtl_align_up(len + 1, 4) / 4) + 1;
                break;
            }
            case FDT_END_NODE:{
                rtl_print("FDT_END_NODE\n");
                return offset;
                break;
            }
            case FDT_PROP:{
                rtl_print("\tFDT_PROP\n");
                offset++;
                FdtProp* prop = (FdtProp*)(cells + offset);
                rtl_printf("\t\t%s, %d, 0x%x\n", 
                        dev_fdt_get_string(info, rtl_bswap32(prop->nameOffset)), 
                        rtl_bswap32(prop->length), rtl_bswap32(prop->nameOffset));
                offset += (rtl_align_up(rtl_bswap32(prop->length), 4) / 4)  + 2;
                break;
            }
            default:{
                rtl_printf("\t\tunknown data at %d (index is %d)\n", offset, value);
                offset+=2;
            }
        }
    }
    return offset;
}


// its a mess and it doesn't even work, gotta fix it
void dev_fdt_dump(FdtInfo* info){
    u32* cells = (u32*)(info->fdtAddress + info->header.dtStructOffset);
    uptr size = info->header.dtStructSize / sizeof(u32);
    const char* style = "------------------------------------------------------------\n";
    rtl_print("\n");
    rtl_print(style);
    for(u32 i = 0; i < size; i++){
        
        if(rtl_bswap32(cells[i]) != FDT_BEGIN_NODE) continue;
        rtl_printf("node found at %d!\n", i);
        i = dev_fdt_print_node(info, cells, size, i);
        EXIT:
       
    }
    rtl_print(style);
    rtl_print("\n");
}

// void dev_fdt_get_node(FdtNode* node, FdtInfo* info){
    
// }

