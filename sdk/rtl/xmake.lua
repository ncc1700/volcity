

target("rtl")
    set_kind("static")
    set_targetdir("../../output-$(vplatform)/sdk")
    set_filename("librtl.a")
    set_toolchains("clang-elf")
    add_includedirs("../includes")
    add_files("src/*.c")
    if is_config("varch", "riscv64") then
        add_cflags("-target riscv64-none-unknown-elf -DBIT64 -mcmodel=medany", {force = true})
        add_asflags("-target riscv64-none-unknown-elf -DBIT64 -mcmodel=medany", {force = true})
    elseif is_config("varch", "arm") then
        add_cflags("-target arm-none-eabi -DBIT32", {force = true})
        add_asflags("-target arm-none-eabi -DBIT32", {force = true})
    end
    add_cflags("-ffreestanding -nostdlib -Wall -Werror -D_VA_ARG", {force = true})
    add_asflags("-ffreestanding -nostdlib -Wall -Werror", {force = true})

