#include "include/terminal.h"
#include "include/lib.h"
#include "include/pong.h"

size_t terminal_row;
size_t terminal_column;
size_t cursor_pos;
uint8_t terminal_color;
uint16_t *terminal_buffer;
enum vga_color color_fg = VGA_COLOR_LIGHT_GREY;
enum vga_color color_bg = VGA_COLOR_BLACK;
/**/
/* uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) { */
/*   return fg | bg << 4; */
/* } */
/**/
/* uint16_t vga_entry(unsigned char uc, uint8_t color) { */
/*   return (uint16_t)uc | (uint16_t)color << 8; */
/* } */
/**/
/* void terminal_init() { */
/*   terminal_color = vga_entry_color(color_fg, color_bg); */
/*   terminal_buffer = (uint16_t *)0xB8000; */
/*   terminal_clear(); */
/*   terminal_begin_line(); */
/* } */
/**/
/* void terminal_begin_line() { */
/*   terminal_setcolor(VGA_COLOR_LIGHT_GREEN); */
/*   terminal_writestring("$ "); */
/*   terminal_setcolor(color_fg); */
/* } */
/**/
/* void terminal_clear() { */
/*   for (size_t y = 0; y < VGA_HEIGHT; y++) { */
/*     for (size_t x = 0; x < VGA_WIDTH; x++) { */
/*       const size_t index = y * VGA_WIDTH + x; */
/*       terminal_buffer[index] = vga_entry(' ', terminal_color); */
/*     } */
/*   } */
/**/
/*   terminal_row = 0; */
/*   terminal_column = 0; */
/*   cursor_pos = 0; */
/**/
/*   terminal_move_cursor(cursor_pos); */
/* } */
/**/
/* void terminal_scroll() { */
/*   for (size_t y = 1; y < VGA_HEIGHT; y++) { */
/*     for (size_t x = 0; x < VGA_WIDTH; x++) { */
/*       const size_t src_index = y * VGA_WIDTH + x; */
/*       const size_t dest_index = (y - 1) * VGA_WIDTH + x; */
/*       terminal_buffer[dest_index] = terminal_buffer[src_index]; */
/*     } */
/*   } */
/**/
/*   for (size_t x = 0; x < VGA_WIDTH; x++) { */
/*     terminal_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = */
/*         vga_entry(' ', terminal_color); */
/*   } */
/**/
/*   terminal_row--; */
/* } */
/**/
/* void terminal_newline() { */
/*   if (++terminal_row == VGA_HEIGHT) { */
/*     terminal_scroll(); */
/*   } */
/**/
/*   terminal_column = 0; */
/*   cursor_pos = terminal_row * VGA_WIDTH; */
/* } */
/**/
/* void terminal_setcolor(uint8_t color) { terminal_color = color; } */
/**/
/* void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) { */
/*   const size_t index = y * VGA_WIDTH + x; */
/*   terminal_buffer[index] = vga_entry(c, color); */
/* } */
/**/
/* void terminal_putchar(char c) { */
/*   if (c == '\n') { */
/*     terminal_newline(); */
/*   } else { */
/**/
/*     cursor_pos++; */
/*     terminal_putentryat(c, terminal_color, terminal_column, terminal_row); */
/*     if (++terminal_column == VGA_WIDTH) { */
/*       terminal_newline(); */
/*     } */
/*   } */
/*   terminal_move_cursor(cursor_pos); */
/* } */
/**/
/* void terminal_write(const char *data, size_t size) { */
/*   for (size_t i = 0; i < size; i++) */
/*     terminal_putchar(data[i]); */
/* } */
/**/
/* void terminal_writestring(const char *data) { */
/*   terminal_write(data, strlen(data)); */
/* } */
/**/
/* void terminal_move_cursor(short pos) { */
/*   outb(0x3D4, 14); */
/*   outb(0x3D5, ((pos >> 8) & 0x00FF)); */
/*   outb(0x3D4, 15); */
/*   outb(0x3D5, pos & 0x00FF); */
/* } */
/**/
/* void terminal_backspace() { */
/*   terminal_column--; */
/*   terminal_putchar(' '); */
/*   terminal_column--; */
/*   terminal_move_cursor(cursor_pos -= 2); */
/* } */
/**/
/* void terminal_command_not_found(const char *command) { */
/*   terminal_putchar('\n'); */
/*   terminal_setcolor(VGA_COLOR_RED); */
/*   terminal_writestring("Command not found: "); */
/*   terminal_setcolor(color_fg); */
/*   terminal_writestring(command); */
/* } */
/**/
/* void terminal_echo(const char *args) { */
/*   terminal_newline(); */
/*   terminal_writestring(args); */
/* } */
/**/
void terminal_execute_command(const char *command) {
  /* if (strcmp(command, "clear") == 0) { */
  /*   terminal_clear(); */
  /*   terminal_row--; */
  /* } else if (strncmp(command, "echo ", 5) == 0) { */
  /*   terminal_echo(command + 5); */
  /* } else if (strcmp(command, "pong") == 0) { */
  /*   pong_init(); */
  /* } else { */
  /*   terminal_command_not_found(command); */
  /* } */
}

void terminal_handle_input(char c) {
  static char command_buffer[256];
  static size_t command_length = 0;

  /* if (c == '\b') { */
  /*   if (command_length > 0) { */
  /*     terminal_backspace(); */
  /*     command_length--; */
  /*   } */
  /* } else if (c == '\n') { */
  /*   if (command_length > 0) { */
  /*     command_buffer[command_length] = '\0'; */
  /*     terminal_execute_command(command_buffer); */
  /*     command_length = 0; */
  /*   } */
  /*   terminal_putchar(c); */
  /*   terminal_begin_line(); */
  /* } else { */
  /*   if (command_length < sizeof(command_buffer) - 1) { */
  /*     command_buffer[command_length++] = c; */
  /*     terminal_putchar(c); */
  /*   } */
  }
/* } */
