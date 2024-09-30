#include "include/idt.h"
#include "include/pic.h"
#include "include/terminal.h"
#include "include/vga.h"

int main() {
  enum vga_color color_fg = VGA_COLOR_LIGHT_GREY;
  enum vga_color color_bg = VGA_COLOR_BLACK;

  terminal_initialize(color_fg, color_bg);
  pic_init();
  idt_init();

  terminal_writestring("test\n");
  terminal_writestring("test");

  while (1) {
  }

  return 0;
}
