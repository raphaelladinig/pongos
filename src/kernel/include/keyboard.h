#ifndef KEYBOARD_H
#define KEYBOARD_H

char scancode_to_ascii(unsigned char scan_code);
extern void (*keyboard_handle_input)();
char keyboard_get_input();

#endif
