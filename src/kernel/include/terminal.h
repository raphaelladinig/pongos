#ifndef TERMINAL_H
#define TERMINAL_H

#include "vga.h"
#include <stddef.h>
#include <stdint.h>

void terminal_init();
void terminal_setcolor(uint8_t color);
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
void terminal_putchar(char c);
void terminal_write(const char *data, size_t size);
void terminal_writestring(const char *data);
void terminal_move_cursor(short pos);
void terminal_handle_input(char c);
void terminal_backspace();
void terminal_newline();
void terminal_begin_line();
void terminal_clear();
void terminal_scroll();
void terminal_execute_command(const char *command);
void terminal_command_not_found(const char *command);
void terminal_echo(const char *args);

#endif
