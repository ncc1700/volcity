includes("volkrnl")
includes("sdk/rtl")

option("varch")
    set_default("riscv64")
    set_values("riscv64", "riscv32")

option("vplatform")
    set_default("qvirt-riscv64")
    set_values("qvirt-riscv64", "qvirt-riscv32")



target("volcity")
    set_kind("phony")
    set_options("varch", "vplatform")
    add_deps("volkrnl")




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