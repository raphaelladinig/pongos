#ifndef LIB_H
#define LIB_H

#include <stddef.h>

size_t strlen(const char*);
void print(const char *data);
void println(const char *data);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);

#endif
