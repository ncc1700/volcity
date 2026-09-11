#include <memory/memory.h>




u8* bitMap = NULL;







boolean mem_setup_pmm(MemoryMap* memMap){
    (void)memMap;
    // STUB
    return FALSE;
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