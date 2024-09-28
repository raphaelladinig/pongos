default:
  @just --list

build:
  ./scripts/build.sh

clean:
  rm -rf out

run:
  qemu-system-i386 -drive format=raw,file=out/sou.iso
