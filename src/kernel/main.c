#include "include/interrupts.h"
#include "include/terminal.h"
#include "include/vga.h"

void init();

int main() {
  init();

  video_init();

  while (1) {
  }

  return 0;
}

void init() {
  terminal_init();
  interrupts_init();
}
