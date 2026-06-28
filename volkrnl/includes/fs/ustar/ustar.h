#ifndef USTAR_H_INCLUDED
#define USTAR_H_INCLUDED








#include <types.h>



volatile typedef struct _UStarHeader {
    u8 fileName[100];
    u64 mode;
    u64 oUserId;
    u64 gUserId;
    u8 fileSize[12];
    u8 lastModificationDate[12];
    u64 hrChecksum;
    u8 typeFlag;
    u8 linkedFile[100];
    u8 uStarMagic[6];
    u8 uStarVer[2];
    u8 oUserName[32];
    u8 oGroupName[32];
    u64 devMajor;
    u64 devMinor;
    u8 fileNamePrefix[155];
    u8 padding[12];
} __attribute__((packed)) UStarHeader;

UStarHeader* ustar_get_header(uptr address, uptr offset);
usize ustar_get_filesize_from_header(UStarHeader* header);
void ustar_list_all_from_memory(uptr address);
UStarHeader* ustar_find_file_from_memory(uptr address, const char* fileName);
u8* ustar_get_filedata_from_memory(UStarHeader* header);







#endif
