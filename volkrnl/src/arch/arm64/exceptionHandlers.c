#include <coredev/uart.h>
#include <core/core.h>








void unknown_exception(){
    core_panic("an unknown exception has been called");
}



void error_exception(){
    core_panic("a synchronous exception has occured");
}