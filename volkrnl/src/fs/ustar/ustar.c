#include <fs/ustar/ustar.h>
#include <rtl/string.h>
#include <rtl/print.h>


UStarHeader* ustar_get_header_from_memory(uptr address, uptr offset){
    UStarHeader* header = (UStarHeader*)(address + offset);
    if(rtl_equal_cstring_ex((const char*)header->uStarMagic, "ustar", 5)){
        return header;
    } else {
        return NULL;
    }
}

usize ustar_get_filesize_from_header(UStarHeader* header){
    return rtl_oct_string_to_usize((const unsigned char*)header->fileSize, 11);
}

void ustar_list_all_from_memory(uptr address){
    uptr offset = 0;
    UStarHeader* header = ustar_get_header_from_memory(address, offset);
    do {
        usize fileSize = ustar_get_filesize_from_header(header);
        offset += (((fileSize + (sizeof(UStarHeader) - 1)) / sizeof(UStarHeader)) + 1) * sizeof(UStarHeader);
        rtl_printf("name: %s, size: %d\n", header->fileName, ustar_get_filesize_from_header(header));
        header = ustar_get_header_from_memory(address, offset);
    } while(header != NULL && rtl_equal_cstring_ex((const char*)header->uStarMagic, "ustar", 5));
}


UStarHeader* ustar_find_file_from_memory(uptr address, const char* fileName){
    uptr offset = 0;
    UStarHeader* header = ustar_get_header_from_memory(address, offset);
    do {
        if(rtl_equal_cstring((const char*)header->fileName, fileName)){
            return header;
        }
        usize fileSize = ustar_get_filesize_from_header(header);
        offset += (((fileSize + (sizeof(UStarHeader) - 1)) / sizeof(UStarHeader)) + 1) * sizeof(UStarHeader);
        header = ustar_get_header_from_memory(address, offset);
    } while(header != NULL && rtl_equal_cstring_ex((const char*)header->uStarMagic, "ustar", 5));
    return NULL;
}


u8* ustar_get_filedata_from_memory(UStarHeader* header){
    return (u8*)((uptr)header + sizeof(UStarHeader));
}
