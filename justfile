default:
  @just --list

build-bootloader:
  #!/bin/sh

  if [ ! -d "out" ]; then
    mkdir -p out
  fi

  nasm src/boot.asm -f bin -o out/boot.bin

build-kernel: 
  #!/bin/sh

  if [ ! -d "out/kernel" ]; then
    mkdir -p out/kernel
  fi

  for file in src/kernel/*.asm; do 
    nasm $file -f elf -o out/kernel/$(basename "${file%.asm}.o")
  done

  for file in src/kernel/*.c; do 
    clang -target i386-unknown-none -ffreestanding -c -Wall -Wextra $file -o out/kernel/$(basename "${file%.c}.o")
  done

  object_files=$(find out/kernel -name '*.o' ! -name 'entry.o')
  clang -m32 -T src/kernel/linker.ld out/kernel/entry.o $object_files -nostdlib -o out/kernel/kernel.bin

build: build-bootloader build-kernel
  cat out/boot.bin out/kernel/kernel.bin > out/sou.iso

clean:
  rm -rf out

clean-build: clean build

run:
  qemu-system-x86_64 -drive format=raw,file=out/sou.iso

build-run: clean-build run
