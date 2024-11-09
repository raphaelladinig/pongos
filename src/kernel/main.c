#include "include/interrupts.h"
#include "include/terminal.h"

int main() {
  interrupts_init();
  terminal_init();

  while (1) {
  }

  return 0;
}
