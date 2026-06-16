qvirt-riscv64:
	xmake f --varch=riscv64 --vplatform=qvirt-riscv64
	xmake build volcity

qvirt-riscv32:
	xmake f --varch=riscv32 --vplatform=qvirt-riscv32
	xmake build volcity

qemu-riscv64:
	make qvirt-riscv64
	rm -f output-qvirt-riscv64/makefile
	echo -e "all:\n\t tar -cvf initfs.tar ." >> output-qvirt-riscv64/makefile
	cd output-qvirt-riscv64 && make
	qemu-system-riscv64 -machine virt \
		-bios none -kernel output-qvirt-riscv64/core/volkrnl.elf -initrd output-qvirt-riscv64/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl 	

rv64-debug:
	qemu-system-riscv64 -machine virt \
		-bios none -kernel output-qvirt-riscv64/core/volkrnl.elf -initrd output-qvirt-riscv64/initfs.tar -m 96M \
		-device ramfb -serial mon:stdio -display sdl -S -s
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
	rm -rf .xmake
	rm -rf build

#  cargo build --target=aarch64-unknown-none