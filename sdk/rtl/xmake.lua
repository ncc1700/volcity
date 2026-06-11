

target("rtl")
    set_kind("static")
    set_toolchains("clang-$(varch)")
    add_includedirs("../includes")
    add_files("src/*.c")
    if is_config("varch", "riscv64") then
        add_cflags("-DBIT64", {force = true})
    end
    if is_config("varch", "riscv32") then
        add_cflags("-DBIT32", {force = true})
    end
    add_cflags("-target $(varch)-none-elf -mcmodel=medany -ffreestanding -nostdlib -Wall -Werror -D_VA_ARG", {force = true})
    add_asflags("-target $(varch)-none-elf -mcmodel=medany -ffreestanding -nostdlib -Wall -Werror", {force = true})

