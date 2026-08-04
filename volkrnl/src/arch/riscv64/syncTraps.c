#include <platform/platform.h>
#include <rtl/print.h>
#include <arch/riscv64/archdef.h>
#include <kernel/kernel.h>





void ins_addr_misaligned(){
    kern_panic("Instruction address misaligned\n");
}

void ins_access_fault(){
    kern_panic("Instruction access fault\n");
}

void illegal_instruction(){
    kern_panic("Illegal instruction\n");
}

void load_address_misaligned(){
    kern_panic("Load address misaligned\n");
}

void load_access_fault(){
    kern_panic("Load access fault\n");
}


void store_address_misaligned(){
    kern_panic("Store address misaligned\n");
}

void store_access_fault(){
    kern_panic("Store access fault\n");
}

void ins_page_fault(){
    kern_panic("Instruction page fault\n");
}

void load_page_fault(){
    kern_panic("Load page fault\n");
}

void store_page_fault(){
    kern_panic("Store page fault\n");
}