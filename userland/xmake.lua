includes("test")

target("userland")
    set_kind("phony")
    add_deps("test")






toolchain("clang-wasm")
    set_kind("standalone")
    set_toolset("cc", "clang")
    set_toolset("as", "clang")
    set_toolset("ld", "clang")
toolchain_end()
