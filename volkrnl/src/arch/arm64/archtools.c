#include <arch/arch.h>








void halt(){
    __asm__("wfi");
}