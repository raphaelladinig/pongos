#include "include/video.h"
#include "include/io.h"

#define PALETTE_MASK 0x3C6
#define PALETTE_READ 0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char u8;

void video_init() {
  outb(PALETTE_MASK, 0xFF);
  outb(PALETTE_WRITE, 0);
  for (u8 i = 0; i < 255; i++) {
    outb(PALETTE_DATA, (((i >> 5) & 0x7) * (256 / 8)) / 4);
    outb(PALETTE_DATA, (((i >> 2) & 0x7) * (256 / 8)) / 4);
    outb(PALETTE_DATA, (((i >> 0) & 0x3) * (256 / 4)) / 4);
  }

  outb(PALETTE_DATA, 0x3F);
  outb(PALETTE_DATA, 0x3F);
  outb(PALETTE_DATA, 0x3F);
}
