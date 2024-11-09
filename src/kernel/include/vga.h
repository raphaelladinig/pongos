#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>

#define VGA_WIDTH 320
#define VGA_HEIGHT 200

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
