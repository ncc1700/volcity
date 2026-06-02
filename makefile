qvirt-arm64:
	cd volkrnl && xmake build qvirt-arm64

qvirt-riscv64:
	cd volkrnl && xmake build qvirt-riscv64

qemu-arm64:
	make qvirt-arm64
	rm -f output-qvirt-riscv64/makefile
	echo -e "all:\n\t tar -cvf initfs.tar ." >> output-qvirt-arm64/makefile
	cd output-qvirt-arm64 && make
	qemu-system-aarch64 -cpu cortex-a55 -machine virt \
		-kernel output-qvirt-arm64/core/volkrnl.elf -initrd output-qvirt-arm64/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl 	

qemu-riscv64:
	make qvirt-riscv64
	rm -f output-qvirt-riscv64/makefile
	echo -e "all:\n\t tar -cvf initfs.tar ." >> output-qvirt-riscv64/makefile
	cd output-qvirt-riscv64 && make
	qemu-system-riscv64 -machine virt \
		-bios none -kernel output-qvirt-riscv64/core/volkrnl.elf -initrd output-qvirt-riscv64/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl 	
clean:
	cd volkrnl && make clean
	rm -rf output-*
	rm -rf initfs.tar

#  cargo build --target=aarch64-unknown-none