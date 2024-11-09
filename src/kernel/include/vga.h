#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>

#define VGA_WIDTH 320
#define VGA_HEIGHT 200

enum vga_color {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE = 1,
  VGA_COLOR_GREEN = 2,
  VGA_COLOR_CYAN = 3,
  VGA_COLOR_RED = 4,
  VGA_COLOR_MAGENTA = 5,
  VGA_COLOR_BROWN = 6,
  VGA_COLOR_LIGHT_GREY = 7,
  VGA_COLOR_DARK_GREY = 8,
  VGA_COLOR_LIGHT_BLUE = 9,
  VGA_COLOR_LIGHT_GREEN = 10,
  VGA_COLOR_LIGHT_CYAN = 11,
  VGA_COLOR_LIGHT_RED = 12,
  VGA_COLOR_LIGHT_MAGENTA = 13,
  VGA_COLOR_LIGHT_BROWN = 14,
  VGA_COLOR_WHITE = 15,
};

struct rectangle {
  int x;
  int y;
  int height;
  int width;
  unsigned char color;
};

void draw_rectangle(struct rectangle *rectangle);
void erase_rectangle(struct rectangle *rectangle);
void fill_screen(unsigned char color);
void clear_screen();
void switch_to_video_mode();
void switch_to_text_mode();
void draw_char(int x, int y, char c, unsigned char color);
void draw_text(int x, int y, const char *text, unsigned char color);

#endif
