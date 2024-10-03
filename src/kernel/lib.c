#include <stddef.h>
#include "include/terminal.h"

size_t strlen(const char *str) {
  size_t len = 0;
  while (str[len])
    len++;
  return len;
}

void print(const char *data) {
  terminal_write(data, strlen(data));
}

void println(const char *data) {
  terminal_write(data, strlen(data));
  terminal_putchar('\n');
}
