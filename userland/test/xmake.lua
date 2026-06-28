target("test")
    set_kind("binary")
    set_toolchains("clang-wasm")
   set_targetdir("../../output-$(vplatform)/apps")
    add_files("src/*.c")
    add_cflags("-target wasm64 -ffreestanding -nostdlib -Wall -Werror", {force = true})
    add_asflags("-target wasm64 -ffreestanding -nostdlib -Wall -Werror", {force = true})
    add_ldflags("-target wasm64 -ffreestanding -nostdlib -Wall -Werror", {force = true})

