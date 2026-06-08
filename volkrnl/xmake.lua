target("qvirt-riscv64")
    set_toolchains("clang-riscv64")
    set_targetdir("../output-qvirt-riscv64/core")
    set_filename("volkrnl.elf")
    add_includedirs("includes")
    add_files("src/*.c", "src/rtl/*.c", "src/core/*.c")
    add_files("src/platform/qvirt-riscv64/*.S", 
              "src/platform/qvirt-riscv64/*.c")    
    add_files("src/arch/riscv64/*.S", 
              "src/arch/riscv64/*.c")   
    add_files("src/coredev/uart/pl011/*.c", "src/coredev/devtree/*.c")

    add_cflags("-target riscv64-none-elf -mcmodel=medany -ffreestanding -DBIT64 -nostdlib -Wall -Werror -D_VA_ARG", {force = true})
    add_asflags("-target riscv64-none-elf -mcmodel=medany -ffreestanding -DBIT64 -nostdlib -Wall -Werror", {force = true})
    add_ldflags("-nostdlib -Tlinker/qvirt-riscv64/linker.ld", {force = true})


target("qvirt-riscv32")
    set_toolchains("clang-riscv32")
    set_targetdir("../output-qvirt-riscv32/core")
    set_filename("volkrnl.elf")
    add_includedirs("includes")
    add_files("src/*.c", "src/rtl/*.c", "src/core/*.c")
    add_files("src/platform/qvirt-riscv32/*.S", 
              "src/platform/qvirt-riscv32/*.c")    
    add_files("src/arch/riscv32/*.S", 
              "src/arch/riscv32/*.c")   
    add_files("src/coredev/uart/pl011/*.c", "src/coredev/devtree/*.c")

    add_cflags("-target riscv32-none-elf -mcmodel=medany -ffreestanding -DBIT32 -nostdlib -Wall -Werror -D_VA_ARG", {force = true})
    add_asflags("-target riscv32-none-elf -mcmodel=medany -ffreestanding -DBIT32 -nostdlib -Wall -Werror", {force = true})
    add_ldflags("-nostdlib -Tlinker/qvirt-riscv32/linker.ld", {force = true})


toolchain("clang-riscv64")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()

toolchain("clang-riscv32")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()