includes("volkrnl")

target("qvirt-aarch64")
    set_kind("phony")
    add_deps("volkrnl-qvirt-aarch64")

toolchain("clang-arm64")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "ld.lld")
toolchain_end()