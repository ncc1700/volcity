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
    info->cells = (u32*)(info->fdtAddress + info->header.dtStructOffset);
    info->cellAmount = info->header.dtStructSize / sizeof(u32);
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




void dev_fdt_print_node(FdtInfo* info, u32 offset){
    while(offset < info->cellAmount){
        u32 value = rtl_bswap32(info->cells[offset]);
        switch(value){
            case FDT_BEGIN_NODE:{
                rtl_print("FDT_BEGIN_NODE\n");
                const char* name = (const char*)(info->cells + offset + 1);
                rtl_print(name);
                rtl_print("\n");
                usize len = rtl_get_cstring_len(name);
                offset += (rtl_align_up(len + 1, 4) / 4) + 1;
                break;
            }
            case FDT_END_NODE:{
                rtl_print("FDT_END_NODE\n");
                return;
                break;
            }
            case FDT_PROP:{
                rtl_print("\tFDT_PROP\n");
                offset++;
                FdtProp* prop = (FdtProp*)(info->cells + offset);
                rtl_printf("\t\t%s, %d, 0x%x\n", 
                        dev_fdt_get_string(info, rtl_bswap32(prop->nameOffset)), 
                        rtl_bswap32(prop->length), rtl_bswap32(info->cells[offset + 2]));
                offset += (rtl_align_up(rtl_bswap32(prop->length), 4) / 4)  + 2;
                break;
            }
            default:{
                rtl_printf("\t\tunknown data at %d (index is %d)\n", offset, value);
                offset+=2;
            }
        }
    }
}

// absoloutly horrendous code
// its also very unsafe, TODO: make it safe!!!
void dev_fdt_print_node_and_step(FdtInfo* info, u32* offset){
    while(*offset < info->cellAmount){
        u32 value = rtl_bswap32(info->cells[*offset]);
        switch(value){
            case FDT_BEGIN_NODE:{
                rtl_print("FDT_BEGIN_NODE\n");
                const char* name = (const char*)(info->cells + *offset + 1);
                rtl_print(name);
                rtl_print("\n");
                usize len = rtl_get_cstring_len(name);
                *offset += (rtl_align_up(len + 1, 4) / 4) + 1;
                break;
            }
            case FDT_END_NODE:{
                rtl_print("FDT_END_NODE\n");
                return;
                break;
            }
            case FDT_PROP:{
                rtl_print("\tFDT_PROP\n");
                *offset += 1;;
                FdtProp* prop = (FdtProp*)(info->cells + *offset);
                rtl_printf("\t\t%s, %d, 0x%x\n", 
                        dev_fdt_get_string(info, rtl_bswap32(prop->nameOffset)), 
                        rtl_bswap32(prop->length), rtl_bswap32(info->cells[*offset + 2]));
                *offset += (rtl_align_up(rtl_bswap32(prop->length), 4) / 4)  + 2;
                break;
            }
            default:{
                rtl_printf("\t\tunknown data at %d (index is %d)\n", *offset, value);
                *offset+=2;
            }
        }
    }
}


// its a mess and it doesn't even work, gotta fix it
void dev_fdt_dump(FdtInfo* info){
    const char* style = "------------------------------------------------------------\n";
    rtl_print("\n");
    rtl_print(style);
    for(u32 i = 0; i < info->cellAmount; i++){
        if(rtl_bswap32(info->cells[i]) != FDT_BEGIN_NODE) continue;
        rtl_printf("node found at %d!\n", i);
        dev_fdt_print_node_and_step(info, &i);
       
    }
    rtl_print(style);
    rtl_print("\n");
}

boolean dev_fdt_find_node(FdtInfo* info, const char* nodeName, u32* nodeOffset){
    for(u32 i = 0; i < info->cellAmount; i++){
        if(rtl_bswap32(info->cells[i]) != FDT_BEGIN_NODE) continue;
        const char* name = (const char*)(info->cells + i + 1);
        if(rtl_compare_cstring(name, nodeName) == 0){
            *nodeOffset = i;
            return TRUE;
        } else {
            usize len = rtl_get_cstring_len(name);
            i += (rtl_align_up(len + 1, 4) / 4) + 1;
        }
    }
    *nodeOffset = 0;
    return FALSE;
}

FdtProp* dev_fdt_get_prop_ex(FdtInfo* info, u32 nodeOffset, const char* propName, u32* propOffset){
    u32 offset = nodeOffset;
    while(offset < info->cellAmount){
        u32 value = rtl_bswap32(info->cells[offset]);
        switch(value){
            case FDT_BEGIN_NODE:{
                const char* name = (const char*)(info->cells + offset + 1);
                usize len = rtl_get_cstring_len(name);
                offset += (rtl_align_up(len + 1, 4) / 4) + 1;
                break;
            }
            case FDT_END_NODE:{
                *propOffset = 0;
                return NULL;
                break;
            }
            case FDT_PROP:{
                rtl_print("\tFDT_PROP\n");
                offset++;
                FdtProp* prop = (FdtProp*)(info->cells + offset);
                const char* name = dev_fdt_get_string(info, rtl_bswap32(prop->nameOffset));
                rtl_printf("name is %s\n", name);
                if(rtl_compare_cstring(propName, name) == 0){
                    *propOffset = offset;
                    return prop;
                }
                offset += (rtl_align_up(rtl_bswap32(prop->length), 4) / 4)  + 2;
                break;
            }
            default:{
                rtl_printf("\t\tunknown data at %d (index is %d)\n", offset, value);
                offset+=2;
            }
        }
    }
    *propOffset = 0;
    return NULL;
}

FdtProp* dev_fdt_get_prop(FdtInfo* info, u32 nodeOffset, const char* propName){
    u32 pOffset = 0;
    return dev_fdt_get_prop_ex(info, nodeOffset, propName, &pOffset);
}


u32 dev_fdt_get_value_from_prop(FdtInfo* info, u32 propOffset){
    return rtl_bswap32(info->cells[propOffset + 2]);
}

void dev_fdt_get_array_from_prop(FdtInfo* info, u32 propOffset, uptr* array, usize length){
    u32 offset = propOffset + 2;
    for(usize i = 0; i < length; i++){
        array[i] = rtl_bswap32(info->cells[offset + i]);
    }
}

// doesn't work
// const char* dev_fdt_get_string_from_prop(FdtInfo* info, u32 propOffset){
//     return dev_fdt_get_string(info, rtl_bswap32(info->cells[propOffset + 2]));
// }
