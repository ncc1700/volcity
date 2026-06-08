qvirt-riscv64:
	cd volkrnl && xmake build qvirt-riscv64

qvirt-riscv32:
	cd volkrnl && xmake build qvirt-riscv32

qemu-riscv64:
	make qvirt-riscv64
	rm -f output-qvirt-riscv64/makefile
	echo -e "all:\n\t tar -cvf initfs.tar ." >> output-qvirt-riscv64/makefile
	cd output-qvirt-riscv64 && make
	qemu-system-riscv64 -machine virt \
		-bios none -kernel output-qvirt-riscv64/core/volkrnl.elf -initrd output-qvirt-riscv64/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl 	

qemu-riscv32:
	make qvirt-riscv32
	rm -f output-qvirt-riscv32/makefile
	echo -e "all:\n\t tar -cvf initfs.tar ." >> output-qvirt-riscv32/makefile
	cd output-qvirt-riscv32 && make
	qemu-system-riscv32 -machine virt \
		-bios none -kernel output-qvirt-riscv32/core/volkrnl.elf -initrd output-qvirt-riscv32/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl 
clean:
	cd volkrnl && make clean
	rm -rf output-*
	rm -rf initfs.tar

#  cargo build --target=aarch64-unknown-none