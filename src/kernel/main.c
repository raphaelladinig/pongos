#include "include/interrupts.h"
#include "include/terminal.h"
#include "include/vga.h"


int main() {
  interrupts_init();
  /* terminal_init(); */

  draw_text(0, 0, "test", 0x0F); 
  struct rectangle rect = {50, 50, 100, 50, 0x5F};
  draw_rectangle(&rect);

  while (1) {
  }

  return 0;
}
