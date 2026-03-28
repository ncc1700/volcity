target("volkrnl-qvirt-aarch64")
    set_toolchains("clang-arm64")
    set_targetdir("../output/core")
    set_filename("volkrnl.elf")

    add_includedirs("includes")

    -- TODO: make it so we add files via the platform and
    -- architecture and drivers people want via
    -- xmake cmdline arguments

    -- common kernel source files
    add_files("src/*.c")

    -- architecture specific source files
    add_files("src/arch/arm64/*.asm", 
              "src/arch/arm64/*.c")

    -- platform specific source files
    add_files("src/platform/qvirt-arm64/*.asm", 
              "src/platform/qvirt-arm64/*.c")
    
    -- core device drivers we include
    add_files("src/coredev/uart/pl011/*.c")

    add_cflags("-target aarch64-none-elf -ffreestanding -nostdlib", {force = true})
    add_asflags("-target aarch64-none-elf -ffreestanding -nostdlib", {force = true})
    add_ldflags("-nostdlib -Tlinker/volkrnl/qvirt-arm64/linker.ld", {force = true})

toolchain("clang-arm64")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()