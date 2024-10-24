#include "include/vga.h"
#include "include/io.h"

int c = 1;

void timer_tick() {
  c++;
  fill_screen(c);
}

void pit_init() {
  outb(0x43, 0x34);
  outb(0x40, 1193180 / 100);
}
