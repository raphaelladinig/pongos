#include "include/interrupts.h"
#include "include/terminal.h"

void init();

int main() {
  init();

  while (1) {
  }

  return 0;
}

void init() {
  terminal_init();
  interrupts_init();
}
