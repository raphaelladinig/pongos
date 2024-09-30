#ifndef KEYBOARD_H
#define KEYBOARD_H

unsigned char read_scan_code();
void keyboard_interrupt_handler();
char scan_code_to_ascii(unsigned char scan_code);

#endif
