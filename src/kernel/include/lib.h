#ifndef LIB_H
#define LIB_H

#include <stddef.h>
#include "io.h"

size_t strlen(const char*);
void print(const char *data);
void println(const char *data);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);

#endif
