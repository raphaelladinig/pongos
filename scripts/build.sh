#!/bin/sh

if [ ! -d "out" ]; then
  mkdir -p out
fi

if [ ! -d "out/kernel" ]; then
  mkdir -p out/kernel
fi

nasm src/boot.asm -f bin -o out/boot.bin
nasm src/kernel_entry.asm -f elf -o out/kernel_entry.o
for file in src/kernel/*.c; do 
  clang -target i386-unknown-none -ffreestanding -c -Wall -Wextra "$file" -o "out/kernel/$(basename "${file%.c}.o")"
done
clang -m32 -T src/linker.ld out/kernel_entry.o out/kernel/*.o -nostdlib -o out/kernel/kernel.bin

cat out/boot.bin out/kernel/kernel.bin > out/sou.iso
