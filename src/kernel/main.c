#include "include/interrupts.h"
#include "include/terminal.h"
#include "include/vga.h"

int main() {
  /* terminal_init(); */
  interrupts_init();
  
  fill_screen(1);

  while (1) {
  }

  return 0;
}
