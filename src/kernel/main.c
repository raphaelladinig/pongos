#include "include/idt.h"
#include "include/terminal.h"
#include "include/vga.h"
#include "include/pic.h"

int main() {
  enum vga_color color_fg = VGA_COLOR_LIGHT_GREY;
  enum vga_color color_bg = VGA_COLOR_BLACK;

  terminal_initialize(color_fg, color_bg);
  idt_init();
  pic_init();
  
  terminal_writestring("test\n");
  terminal_writestring("test");

  return 0;
}
