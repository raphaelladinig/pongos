#!/bin/sh

if [ ! -d "out" ]; then
  mkdir -p out
fi

if [ ! -d "out/kernel" ]; then
  mkdir -p out/kernel
fi

if [ ! -d "out/kernel/c" ]; then
  mkdir -p out/kernel/c
fi

nasm src/boot.asm -f bin -o out/boot.bin
nasm src/kernel/entry.asm -f elf -o out/kernel/entry.o
nasm src/kernel/io.asm -f elf -o out/kernel/io.o
for file in src/kernel/*.c; do 
  clang -target i386-unknown-none -ffreestanding -c -Wall -Wextra "$file" -o "out/kernel/c/$(basename "${file%.c}.o")"
done
clang -m32 -T src/kernel/linker.ld out/kernel/entry.o out/kernel/io.o out/kernel/c/*.o -nostdlib -o out/kernel/kernel.bin

cat out/boot.bin out/kernel/kernel.bin > out/sou.iso
