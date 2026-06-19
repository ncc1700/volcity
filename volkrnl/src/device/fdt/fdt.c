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

void dev_fdt_print_all_strings(FdtInfo* info){
    uptr address = info->fdtAddress + info->header.dtStringsOffset;
    uptr offset = 0;
    const char* style = "------------------------------------------------------------\n";
    rtl_print("\n");
    rtl_print(style);
    rtl_print("dumping fdt string table\n");
    rtl_print(style);
    while(offset < info->header.dtStringSize){
        const char* string = (const char*)(address + offset);
        usize len = rtl_get_cstring_len(string);
        offset += len + 1;   
        rtl_print(string);
        rtl_print("\n");    
    }
    rtl_print(style);
    rtl_print("\n");
}

