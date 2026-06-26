
QEMU_MEMORY=96M
QEMU_KERNEL=output-qvirt-riscv64/system/volkrnl.elf
QEMU_INITRD=output-qvirt-riscv64/initfs.tar

qvirt-riscv64:
	xmake f --varch=riscv64 --vplatform=qvirt-riscv64 -m debug
	xmake build volcity


qemu-riscv64:
	make qvirt-riscv64
	rm -f output-qvirt-riscv64/makefile
	echo -e "all:\n\t tar -cvf initfs.tar system/ sdk/" >> output-qvirt-riscv64/makefile
	cd output-qvirt-riscv64 && make
	qemu-system-riscv64 -machine virt \
		-bios none -kernel $(QEMU_KERNEL) -initrd $(QEMU_INITRD) -m $(QEMU_MEMORY) \
		-device ramfb -serial mon:stdio -display sdl 	

rv64-debug:
	qemu-system-riscv64 -machine virt \
		-bios none -kernel $(QEMU_KERNEL) -initrd $(QEMU_INITRD)  -m $(QEMU_MEMORY) \
		-device ramfb -serial mon:stdio -display sdl -S -s


dump_dtb:
	qemu-system-riscv64 -machine virt \
		-bios none -kernel $(QEMU_KERNEL) -initrd $(QEMU_INITRD) -m $(QEMU_MEMORY) \
		-device ramfb -serial mon:stdio -display sdl -machine dumpdtb=qemu.dtb
	dtc qemu.dtb -o qemu.dtc
clean:
	cd volkrnl && make clean
	rm -rf output-*
	rm -rf initfs.tar
	rm -rf .xmake
	rm -rf build

