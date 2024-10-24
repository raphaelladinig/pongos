#include "include/interrupts.h"
#include "include/terminal.h"
#include "include/vga.h"

void init();

int main() {
  init();

  draw_rectangle(50, 50, 100, 50, 4);
  fill_screen(3);

  while (1) {
  }

  return 0;
}

void init() {
  /* terminal_init(); */
  interrupts_init();
}
