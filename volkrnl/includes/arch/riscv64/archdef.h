#ifndef ARCHDEF_H_INCLUDED
#define ARCHDEF_H_INCLUDED




#include <types.h>


#define MTIMECMP_OFFSET 0x4000
#define MTIME_OFFSET 0xBFF8



typedef struct _RegisterState {
    u64 ra;
    u64 sp;
    u64 gp;
    u64 tp;
    u64 t0;
    u64 t1;
    u64 t2;
    u64 t3;
    u64 t4;
    u64 t5;
    u64 t6;
    u64 fp;
    u64 s1;
    u64 a0;
    u64 a1;
    u64 a2;
    u64 a3;
    u64 a4;
    u64 a5;
    u64 a6;
    u64 a7;
    u64 s2;
    u64 s3;
    u64 s4;
    u64 s5;
    u64 s6;
    u64 s7;
    u64 s8;
    u64 s9;
    u64 s10;
    u64 s11;
    u64 s0;
} RegisterState;




void arch_setup_exceptions();
u64 arch_get_mhartid();
u64 arch_get_mie();
u64 arch_get_mepc();
u64 arch_get_mcause();
u64 arch_get_mtvec();
u64 arch_get_stvec();
u64 arch_get_mscratch();
u64 arch_get_mstatus();

void arch_set_mie(u64 value);
void arch_set_mcause(u64 value);
void arch_set_mtvec(u64 value);
void arch_set_stvec(u64 value);
void arch_set_mscratch(u64 value);
void arch_set_mstatus(u64 value);











#endif