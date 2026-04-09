target("qvirt-arm64")
    set_toolchains("clang-arm64")
    set_targetdir("../output/core")
    set_filename("volkrnl.elf")
    add_includedirs("includes")
    add_files("src/*.c", "src/rtl/*.c")
    add_files("src/platform/qvirt-arm64/*.asm", 
              "src/platform/qvirt-arm64/*.c")    
    add_files("src/coredev/uart/pl011/*.c")

    add_cflags("-target aarch64-none-elf -ffreestanding -nostdlib -Wall", {force = true})
    add_asflags("-target aarch64-none-elf -ffreestanding -nostdlib -Wall", {force = true})
    add_ldflags("-nostdlib -Tlinker/qvirt-arm64/linker.ld", {force = true})

target("stub")
    set_toolchains("clang-arm64")
    set_targetdir("../output/core")
    set_filename("volkrnl.elf")
    add_includedirs("includes")
    add_files("src/*.c")
    add_files("src/platform/stub/*.asm", 
              "src/platform/stub/*.c")    
    add_files("src/coredev/uart/stub/*.c")

    add_cflags("-target aarch64-none-elf -ffreestanding -nostdlib -Wall", {force = true})
    add_asflags("-target aarch64-none-elf -ffreestanding -nostdlib -Wall", {force = true})
    add_ldflags("-nostdlib -Tlinker/stub/linker.ld", {force = true})

toolchain("clang-arm64")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()
