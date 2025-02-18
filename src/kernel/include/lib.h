#ifndef LIB_H
#define LIB_H

#include "io.h"
#include <stddef.h>

size_t strlen(const char *);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);
void *memcpy(void *dest, const void *src, size_t n);

#endif
