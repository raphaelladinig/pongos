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

int strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    while (n && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        n--;
    }
    return n == 0 ? 0 : *(unsigned char *)str1 - *(unsigned char *)str2;
}

void *memcpy(void *dest, const void *src, size_t n) {
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }

    return dest;
}
