#!/bin/bash




xmake build qvirt-aarch64
qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel volkrnl/output/core/volkrnl.elf -serial mon:stdio -device VGA -display sdl