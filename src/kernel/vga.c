#include "include/vga.h"

#define VGA_MODE 0x13
#define VGA_WIDTH 320
#define VGA_HEIGHT 200

void fill_screen(unsigned char color) {
  unsigned char *video_memory = (unsigned char *)0xA0000;
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    video_memory[i] = color;
  }
}

void draw_rectangle(struct rectangle *rectangle) {
  unsigned char *video_memory = (unsigned char *)0xA0000;

  for (int i = 0; i < rectangle->height; i++) {
    for (int j = 0; j < rectangle->width; j++) {
      int pixel_position = (rectangle->y + i) * VGA_WIDTH + (rectangle->x + j);
      video_memory[pixel_position] = rectangle->color;
    }
  }
}

void erase_rectangle(struct rectangle *rectangle) {
  draw_rectangle(&(struct rectangle){rectangle->x, rectangle->y, rectangle->width, rectangle->height, 0});
}

void clear_screen() {
  uint16_t *video_memory = (uint16_t *)0xA0000;
  for (int i = 0; i < 320 * 200; i++) {
    video_memory[i] = 0x20; // Space character
  }
}
