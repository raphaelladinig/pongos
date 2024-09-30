#include "include/interrupts.h"
#include "include/terminal.h"
#include "include/vga.h"

int main() {
  enum vga_color color_fg = VGA_COLOR_LIGHT_GREY;
  enum vga_color color_bg = VGA_COLOR_BLACK;

  terminal_initialize(color_fg, color_bg);

  terminal_writestring("test\n");
  terminal_writestring("test");

  interrupts_init();

  return 0;
}
