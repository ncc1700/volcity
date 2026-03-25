target("volcity")
    set_toolchains("clang-arm64")
    set_targetdir("output/core")
    set_filename("volkrnl.elf")

    add_includedirs("includes")

    -- common source files
    add_files("src/*.c")

    -- platform specific source files
    add_files("src/platform/qvirt-arm64/*.asm", 
              "src/platform/qvirt-arm64/*.c")
    
    -- core device drivers we include
    add_files("src/coredev/pl011/*.c")

    add_cflags("-target aarch64-none-elf -ffreestanding -nostdlib", {force = true})
    add_asflags("-target aarch64-none-elf -ffreestanding -nostdlib", {force = true})
    add_ldflags("-nostdlib -Tlinker/qvirt-arm64/linker.ld", {force = true})



toolchain("clang-arm64")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()