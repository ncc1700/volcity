#include <rtl/print.h>
#include <memory/memory.h>
#include <kernel/kernel.h>
#include <arch/arch.h>
#include <fs/ustar/ustar.h>

void kern_entry(MemoryMap* memMap, InitRdInfo* rdInfo){    
    rtl_printf("\n\nVolcity\n\tbuilt on %s at %s\n\n", __DATE__, __TIME__);    
    usize usableMemory = 0;
    
    for(usize i = 0; i < memMap->amount; i++){
        MemoryEntry entry = memMap->entries[i];
        rtl_printf("base: 0x%lx, end: 0x%lx, size: %ld\n", 
            entry.base, entry.base + entry.size, entry.size);
        if(entry.type == MEM_TYPE_USABLE){
            usableMemory += entry.size;
        }
    }
    
    rtl_print("\n\n");
    ustar_list_all_from_memory(rdInfo->base);
    rtl_print("\n\n");
    UStarHeader* fileHeader = ustar_find_file_from_memory(rdInfo->base, "system/LICENSE.txt");
    if(fileHeader != NULL){
        const char* text = ustar_get_filedata_from_memory(fileHeader);
        rtl_print(text);
        rtl_print("\n");
    } else rtl_printf("couldn't find file");
    
    //UStarHeader* header = ustar_get_header(rdInfo->base, 512);
    //rtl_printf("%s, size: %d\n", header->fileName, ustar_get_filesize_from_header(header));
    //rtl_printf("??\n");
    while(1){continue;}
}


    
