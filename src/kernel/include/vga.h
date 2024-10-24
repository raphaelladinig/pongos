#ifndef VIDEO_H
#define VIDEO_H

#include <stdint.h>

void draw_rectangle(int x, int y, int width, int height, unsigned char color);
void fill_screen(unsigned char color);
void clear_screen();

#endif
