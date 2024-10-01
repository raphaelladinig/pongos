#include "include/keyboard.h"
#include "include/io.h"
#include "include/terminal.h"

unsigned char read_scan_code() { return inb(0x60); };

char scan_code_to_ascii(unsigned char scan_code) {
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
  case 0x14:
    return 's';
  case 0x15:
    return 't';
  case 0x16:
    return 'u';
  case 0x2F:
    return 'v';
  case 0x11:
    return 'w';
  case 0x2D:
    return 'x';
  case 0x2C:
    return 'y';
  case 0x2A:
    return 'z';
  default:
    return 0;
  }
}

void keyboard_handle_input() {
  unsigned char scancode = read_scan_code();

  if (scancode < 0x80) {
    char ascii_char = scan_code_to_ascii(scancode);
    terminal_putchar(ascii_char);
  }
}

/* #define BUFFER_SIZE 128 */
/**/
/* char keyboard_buffer[BUFFER_SIZE]; */
/* int buffer_head = 0; */
/* int buffer_tail = 0; */
/**/
/* char get_next_char() { */
/*   if (buffer_head == buffer_tail) { */
/*     return 0; // Buffer is empty */
/*   } */
/*   char c = keyboard_buffer[buffer_tail]; */
/*   buffer_tail = (buffer_tail + 1) % BUFFER_SIZE; */
/*   return c; */
/* } */
/**/
/* void keyboard_handle_input() { */
/*   // Read the scancode from the keyboard controller */
/*   uint8_t scancode = inb(0x60); */
/**/
/*   // Convert scancode to ASCII (you'll need a mapping for this) */
/*   char ascii_char = scan_code_to_ascii(scancode); */
/**/
/*   // Store the character in the buffer if there's space */
/*   if ((buffer_head + 1) % BUFFER_SIZE != buffer_tail) { */
/*     keyboard_buffer[buffer_head] = ascii_char; */
/*     buffer_head = (buffer_head + 1) % BUFFER_SIZE; */
/*   } */
/**/
/* } */

