#include "include/terminal.h"
#include "include/lib.h"
#include "include/pong.h"
#include "include/vga.h"

size_t terminal_row;
size_t terminal_column;
size_t cursor_pos;
uint8_t terminal_color = 0x0F;

void terminal_init() {
  terminal_clear();
  terminal_begin_line();
}

void terminal_clear() {
  clear_screen();

  terminal_row = 0;
  terminal_column = 0;
  cursor_pos = 0;
}

void terminal_begin_line() { terminal_writestring("$ "); }

void terminal_newline() {
  terminal_row += 8;

  if (terminal_row == VGA_HEIGHT) {
    terminal_init();
  }

  terminal_column = 0;
  cursor_pos = terminal_row * VGA_WIDTH;
}

void terminal_putchar(char c) {
  if (c == '\n') {
    terminal_newline();
  } else {

    cursor_pos++;
    draw_char(terminal_column, terminal_row, c, terminal_color);
    terminal_column += 8;
    if (terminal_column == VGA_WIDTH) {
      terminal_newline();
    }
  }
}

void terminal_write(const char *data, size_t size) {
  for (size_t i = 0; i < size; i++)
    terminal_putchar(data[i]);
}

void terminal_writestring(const char *data) {
  terminal_write(data, strlen(data));
}

void terminal_backspace() {
  terminal_column -= 8;
  erase_rectangle(&(struct rectangle){terminal_column, terminal_row, 8, 8, 0});
}

void terminal_command_not_found(const char *command) {
  terminal_putchar('\n');
  terminal_writestring("command not found ");
  terminal_writestring(command);
}

void terminal_echo(const char *args) {
  terminal_newline();
  terminal_writestring(args);
}

void terminal_execute_command(const char *command) {
  if (strcmp(command, "clear") == 0) {
    terminal_clear();
  } else if (strncmp(command, "echo ", 5) == 0) {
    terminal_echo(command + 5);
  } else if (strcmp(command, "pong") == 0) {
    pong_init();
  } else {
    terminal_command_not_found(command);
  }
}

void terminal_handle_input(char c) {
  static char command_buffer[256];
  static size_t command_length = 0;

  if (c == '\b') {
    if (command_length > 0) {
      terminal_backspace();
      command_length--;
    }
  } else if (c == '\n') {
    if (command_length > 0) {
      command_buffer[command_length] = '\0';
      terminal_execute_command(command_buffer);
      command_length = 0;
    }
    terminal_putchar(c);
    terminal_begin_line();
  } else {
    if (command_length < sizeof(command_buffer) - 1) {
      command_buffer[command_length++] = c;
      terminal_putchar(c);
    }
  }
}
