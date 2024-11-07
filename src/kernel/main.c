#include "include/interrupts.h"
#include "include/pong.h"
#include "include/terminal.h"

int main() {
  terminal_init();
  interrupts_init();
  /* pong_init(); */

  while (1) {
  }

  return 0;
}
