all: balleros.bin

balleros.bin: boot.o kernel.o
	i686-elf-gcc -T linker.ld -o balleros.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

iso: balleros.bin
	cp balleros.bin isodir/boot/balleros.bin
	grub-mkrescue -o balleros.iso isodir
