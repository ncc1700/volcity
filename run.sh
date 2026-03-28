#!/bin/bash




xmake build qvirt-aarch64
xmake run prepare-sys
qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel output/core/volkrnl.elf -initrd initfs.tar -serial mon:stdio -device VGA -display sdl