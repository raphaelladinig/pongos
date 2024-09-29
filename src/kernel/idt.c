#include "include/idt.h"
#include "include/terminal.h"
#include "include/vga.h"

#define IDT_ENTRIES 256

idt_entry_t idt[IDT_ENTRIES];
idt_ptr_t idtp;

void idt_set(int index, uint32_t base, uint16_t selector, uint8_t type_attr) {
  idt[index].offset_low = base & 0xFFFF;
  idt[index].offset_high = (base >> 16) & 0xFFFF;
  idt[index].selector = selector;
  idt[index].zero = 0;
  idt[index].type_attr = type_attr;
}

void divide_by_zero() {
  terminal_setcolor(VGA_COLOR_RED);
  terminal_writestring("\n!!! Divide by zero exception occurred !!!\n");
  while (1) {
  }
}

void idt_init() {
  idtp.base = (uintptr_t)&idt;
  idtp.limit = (sizeof(idt_entry_t) * IDT_ENTRIES) - 1;

  idt_set(0, (uintptr_t)divide_by_zero, 0x08, 0x8E);

  asm volatile("lidt %0" : : "m"(idtp));
}
