



target("volkrnl")
    set_toolchains("clang-$(varch)")
    add_deps("rtl")
    set_targetdir("../output-$(vplatform)/kernel")
    set_filename("volkrnl.elf")
    add_includedirs("includes", "../sdk/includes")
    add_files("src/rtl/*.c", "src/kernel/*.c")
    add_files("src/platform/$(vplatform)/*.S", 
              "src/platform/$(vplatform)/*.c")    
    add_files("src/arch/$(varch)/*.S", 
              "src/arch/$(varch)/*.c")   
    if is_config("varch", "riscv64") then
        add_cflags("-DBIT64", {force = true})
    end
    if is_config("varch", "riscv32") then
        add_cflags("-DBIT32", {force = true})
    end
    add_cflags("-target $(varch)-none-elf -mcmodel=medany -ffreestanding -nostdlib -Wall -Werror ", 
                    "-D_VA_ARG -DPLATFORM=\"$(vplatform)\" -DARCH=\"$(varch)\"", {force = true})
    add_asflags("-target $(varch)-none-elf -mcmodel=medany -ffreestanding -nostdlib -Wall -Werror", {force = true})
    add_ldflags("-nostdlib -Tvolkrnl/linker/$(vplatform)/linker.ld", {force = true})

