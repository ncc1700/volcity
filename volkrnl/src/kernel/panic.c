#include <kernel/kernel.h>
#include <arch/arch.h>
#include <rtl/print.h>




[[noreturn]] void kern_panic(const char* reason){
    rtl_print("\n\n\n------------------------------------------------------------------\n");

    rtl_print("The kernel has panicked: ");
    rtl_print(reason);
    rtl_print("\n------------------------------------------------------------------\n");
    rtl_print("REGISTER STATE: \n\n");
    arch_dump_and_print_registers();
    rtl_print("\n\n------------------------------------------------------------------\n");
    rtl_print("\nPlease restart.\n");

    while(1){arch_halt();continue;}
}
