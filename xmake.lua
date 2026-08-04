includes("volkrnl")
includes("sdk/rtl")
includes("userland")

option("varch")
    set_default("arm")
    set_values("riscv64", "arm")

option("vplatform")
    set_default("integratorcp")
    set_values("qvirt-riscv64", "integratorcp")



target("volcity")
    set_kind("phony")
    set_options("varch", "vplatform")
    add_deps("volkrnl")




toolchain("clang-elf")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()




