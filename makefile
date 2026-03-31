qvirt-arm64:
	cd volkrnl && xmake build volkrnl-qvirt-arm64


initfs:
	tar -cvf initfs.tar output

qemu-arm64:
	make qvirt-arm64
	make initfs
	qemu-system-aarch64 -cpu cortex-a55 -machine virt -kernel \
		output/core/volkrnl.elf -initrd initfs.tar -m 4M \
		-device ramfb -serial mon:stdio -display sdl

clean:
	cd volkrnl && make clean
	rm -rf output
	rm -rf initfs.tar