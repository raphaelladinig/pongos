#include "./terminal.h"

int main() {
  terminal_initialize();

  terminal_writestring("Hello, World!\n");

  return 0;
}
