#include <types.h>
#include <platform/platform.h>
#include <coredev/uart.h>
#include <rtl/string.h>
#include <rtl/print.h>
#include <rtl/mem.h>
#include <coredev/devtree.h>



void k_entry(){
    plat_setup();
    FDTHeader header = {0};
    FDTStringList strList = {0};
    dtree_get_header(&header);
    if(header.magic == 0xd00dfeed){
        uart_cprint("device tree is valid!\n");
    }

    rtl_print_hex("Structure Block: ", dtree_get_structure_block_addr(), TRUE);
    rtl_print_hex("String Block: ", dtree_get_string_block_addr(), TRUE);
    rtl_print_hex("Memory Reservation Block: ", dtree_get_reserved_mem_block_addr(), TRUE);
    u64 addr = dtree_get_string_block_addr();
    dtree_begin_string_list(&strList, addr, header.stringSize);
    do {
        uart_cprint(strList.string);
        uart_cprint("\n");
    } while(dtree_next_string_list(&strList));
    uart_cprint("Done\n");
    while(1){continue;}
}