#include "include/terminal.h"
#include "include/io.h"
#include "include/lib.h"
#include "include/vga.h"

size_t terminal_row;
size_t terminal_column;
size_t cursor_pos;
size_t relative_terminal_column;
uint8_t terminal_color;
uint16_t *terminal_buffer;
enum vga_color color_fg = VGA_COLOR_LIGHT_GREY;
enum vga_color color_bg = VGA_COLOR_BLACK;

void terminal_init() {
  terminal_row = 0;
  terminal_column = 0;
  cursor_pos = 0;
  terminal_color = vga_entry_color(color_fg, color_bg);
  terminal_buffer = (uint16_t *)0xB8000;
  for (size_t y = 0; y < VGA_HEIGHT; y++) {
    for (size_t x = 0; x < VGA_WIDTH; x++) {
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = vga_entry(' ', terminal_color);
    }
  }

  terminal_begin_line();
}

void terminal_begin_line() {
  terminal_setcolor(VGA_COLOR_LIGHT_GREEN);
  relative_terminal_column = 0;
  terminal_writestring("$ ");
  terminal_setcolor(color_fg);
}

void terminal_newline() {
  terminal_row++;
  terminal_column = 0;
  cursor_pos = terminal_row * VGA_WIDTH;
}

void terminal_setcolor(uint8_t color) { terminal_color = color; }

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
  if (c == '\n') {
    terminal_newline();
  } else {
    relative_terminal_column++;

    cursor_pos++;
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH) {
      terminal_column = 0;
      if (++terminal_row == VGA_HEIGHT)
        terminal_row = 0;
    }
  }
  terminal_move_cursor(cursor_pos);
}

void terminal_write(const char *data, size_t size) {
  for (size_t i = 0; i < size; i++)
    terminal_putchar(data[i]);
}

void terminal_writestring(const char *data) {
  terminal_write(data, strlen(data));
}

void terminal_move_cursor(short pos) {
  outb(0x3D4, 14);
  outb(0x3D5, ((pos >> 8) & 0x00FF));
  outb(0x3D4, 15);
  outb(0x3D5, pos & 0x00FF);
}

void terminal_backspace() {
  if (relative_terminal_column <= 5) {
    return;
  }

  relative_terminal_column--;
  terminal_column--;
  terminal_putchar(' ');
  relative_terminal_column--;
  terminal_column--;
  terminal_move_cursor(cursor_pos -= 2);
}

void terminal_handle_input(char c) {
  if (c == '\b') {
    terminal_backspace();
  } else {
    terminal_putchar(c);
  }
  
  if (c == '\n') {
    terminal_begin_line();
  } 
}
