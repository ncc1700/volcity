#!/bin/bash




xmake build volcity
qemu-system-aarch64 -machine virt -cpu cortex-a57 -kernel output/core/volkrnl.elf -serial mon:stdio -display sdl