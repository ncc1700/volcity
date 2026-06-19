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

// its a mess and it doesn't even work, gotta fix it
void dev_fdt_dump(FdtInfo* info){
    uptr address = info->fdtAddress + info->header.dtStructOffset;
    uptr offset = 3;
    const char* style = "------------------------------------------------------------\n";
    rtl_print("\n");
    rtl_print(style);
    rtl_print("dumping fdt\n");
    rtl_print(style);
    
    while(offset < info->header.dtStructSize){
        boolean shouldIncrement = TRUE;
        u32 value = *(u32*)(address + offset);
        switch(value){
            case FDT_BEGIN_NODE:{
                rtl_print("FDT_BEGIN_NODE\n");
                offset += 4;
                u32 nameOffset = *(u32*)(address + offset);
                rtl_print(dev_fdt_get_string(info, nameOffset));
                rtl_print("\n");
                break;
            }
            case FDT_END_NODE:{
                rtl_print("FDT_END_NODE\n");
                goto EXIT;
                break;
            }
            case FDT_PROP:{
                rtl_print("FDT_PROP\n");
                offset += 4;
                FdtProp* prop = (FdtProp*)(address + offset);
                rtl_print(dev_fdt_get_string(info, prop->nameOffset));
                rtl_print("\n");
                if(prop->length > 4){
                    offset += prop->length;
                } else offset += 4;
                break;
            }
            case FDT_NOP:{
                rtl_print("FDT_NOP\n");
                break;
            }
            case FDT_END:{
                rtl_print("FDT_END\n");
                goto EXIT;
                break;
            }
            default:{
                rtl_printf("UNKNOWN?? 0x%x\n", value);
                break;
            }
        }
        if(shouldIncrement == TRUE) offset += 4;
    }
    EXIT:
    rtl_print(style);
    rtl_print("\n");
}

