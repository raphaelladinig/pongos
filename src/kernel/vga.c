#include "include/vga.h"
#include "include/io.h"

#define VGA_MODE 0x13
#define VGA_WIDTH 320
#define VGA_HEIGHT 200

void fill_screen(unsigned char color) {
  unsigned char *video_memory = (unsigned char *)0xA0000;
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    video_memory[i] = color;
  }
}

void draw_rectangle(int x, int y, int width, int height, unsigned char color) {
  unsigned char *video_memory = (unsigned char *)0xA0000;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int pixel_position = (y + i) * VGA_WIDTH + (x + j);
      video_memory[pixel_position] = color;
    }
  }
}

void clear_screen() {
  uint16_t *video_memory = (uint16_t *)0xA0000;
  for (int i = 0; i < 320 * 200; i++) {
    video_memory[i] = 0x20; // Space character
  }
}
