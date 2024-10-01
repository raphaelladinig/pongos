#ifndef KEYBOARD_H
#define KEYBOARD_H

unsigned char read_scan_code();
char scan_code_to_ascii(unsigned char scan_code);
void keyboard_handle_input();
char get_next_char();

#endif
