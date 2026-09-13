#include <memory/memory.h>
#include <rtl/print.h>



u8* bitMap = NULL;
static MemoryMap* memMap = NULL;

const char* memMapTypeToText[] = {
    [MEM_TYPE_USABLE] = "free",
    [MEM_TYPE_UNUSABLE] = "used",
    [MEM_TYPE_MMIO] = "mmio",
    [MEM_TYPE_KERNEL] = "kernel"
};



void mem_dbg_print_memmap(){
    const char* style = "--------------------------------------------------------------------------------\n";
    usize usableMemory = 0;
    rtl_print("\n");
    rtl_print(style);
    rtl_print("dumping memory map\n");
    rtl_print(style);
    for(usize i = 0; i < memMap->amount; i++){
        MemoryEntry entry = memMap->entries[i];
        const char* memMapType;
        if(entry.type >= ARR_SIZE(memMapTypeToText)){
            memMapType = "unknown";
        } else {
            memMapType = memMapTypeToText[entry.type];
        }
        rtl_printf("base: 0x%lx, end: 0x%lx, size: %ld, type: %s\n",
            entry.base, entry.base + entry.size, entry.size, memMapType);
        if(entry.type == MEM_TYPE_USABLE){
            usableMemory += entry.size;
        }
    }
    rtl_print(style);
    rtl_printf("usable memory: %ld/%ld\n", usableMemory, memMap->sizeOfMemory);
    rtl_print(style);
    rtl_print("\n");
}

boolean mem_setup_pmm(MemoryMap* memoryMap){
    memMap = memoryMap;
    // TODO: setup the rest of the physical memory manager
    return TRUE;
}

void* mem_allocate_page(){
    // STUB
    return NULL;
}

void* mem_allocate_pages(usize amountOfPages){
    (void)amountOfPages;
    // STUB
    return NULL;
}

boolean mem_free_page(void* address){
    (void)address;
    // STUB
    return FALSE;
}

boolean mem_free_pages(void* address, usize amountOfPages){
    (void)address;
    // STUB
    return FALSE;
}
