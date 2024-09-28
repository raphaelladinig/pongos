#include "include/idt.h"
#include "./include/terminal.h"

int main() {
  idt_init();
  terminal_initialize();

  terminal_writestring("test");

  return 0;
}
