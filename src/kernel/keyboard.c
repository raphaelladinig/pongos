#include "include/lib.h"
#include "include/keyboard.h"
#include "include/terminal.h"

char scancode_to_ascii(unsigned char scan_code) {
  switch (scan_code) {
  case 0x1E:
    return 'a';
  case 0x30:
    return 'b';
  case 0x2E:
    return 'c';
  case 0x20:
    return 'd';
  case 0x12:
    return 'e';
  case 0x21:
    return 'f';
  case 0x22:
    return 'g';
  case 0x23:
    return 'h';
  case 0x17:
    return 'i';
  case 0x24:
    return 'j';
  case 0x25:
    return 'k';
  case 0x26:
    return 'l';
  case 0x32:
    return 'm';
  case 0x31:
    return 'n';
  case 0x18:
    return 'o';
  case 0x19:
    return 'p';
  case 0x10:
    return 'q';
  case 0x13:
    return 'r';
  case 0x1F:
    return 's';
  case 0x14:
    return 't';
  case 0x16:
    return 'u';
  case 0x2F:
    return 'v';
  case 0x11:
    return 'w';
  case 0x2D:
    return 'x';
  case 0x15:
    return 'y';
  case 0x2C:
    return 'z';
  case 0x1C: 
    return '\n';
  case 0x0E: 
    return '\b';
  default:
    return ' ';
  }
}

void keyboard_handle_input() {
  unsigned char scancode = inb(0x60);

  if (scancode < 0x80) {
    /* terminal_handle_input(scancode_to_ascii(scancode)); */
  }
}
