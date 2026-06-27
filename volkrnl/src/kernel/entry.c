#include <rtl/print.h>
#include <memory/memory.h>
#include <kernel/kernel.h>
#include <arch/arch.h>

void kern_entry(MemoryMap* memMap, InitRdInfo* info){    
    arch_setup();
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

   
    
    while(1){continue;}
}


    
