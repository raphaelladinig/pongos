#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>

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

#endif
