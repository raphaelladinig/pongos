default:
  @just --list

build:
  ./scripts/build.sh

clean:
  rm -rf out

run: clean build
  qemu-system-i386 -drive format=raw,file=out/sou.iso
