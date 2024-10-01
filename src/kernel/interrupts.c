#include "include/interrupts.h"
#include "include/io.h"
#include "include/keyboard.h"
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

void idt_init() {
  idtp.base = (uintptr_t)&idt;
  idtp.limit = (sizeof(idt_entry_t) * IDT_ENTRIES) - 1;

  idt_set(0, (uintptr_t)divide_by_zero_interrupt, 0x08, 0x8E);
  idt_set(33, (uintptr_t)keyboard_interrupt, 0x08, 0x8E);

  asm volatile("lidt %0" : : "m"(idtp));
  asm volatile("sti");
}

#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

void pic_init() {
  // Start the initialization sequence
  outb(PIC1_COMMAND, 0x11);
  outb(PIC2_COMMAND, 0x11);

  // Set the vector offset for the master and slave PIC
  outb(PIC1_DATA, 0x20);
  outb(PIC2_DATA, 0x28);

  // Configure the PIC to work in cascade mode
  outb(PIC1_DATA, 0x04);
  outb(PIC2_DATA, 0x02);

  // Set the operating mode
  outb(PIC1_DATA, 0x01);
  outb(PIC2_DATA, 0x01);

  // Unmask all IRQs (0xFF masks all, so we need to unmask IRQ1)
  outb(PIC1_DATA, 0xFD);
  outb(PIC2_DATA, 0xFF);
}

void interrupts_init() {
  pic_init();
  idt_init();
}

void divide_by_zero_interrupt() {
  terminal_setcolor(VGA_COLOR_RED);
  terminal_writestring("\n!!! Divide by zero exception occurred !!!\n");
  while (1) {
  }
}

void keyboard_interrupt() {
  keyboard_handle_input();
  outb(0x20, 0x20); // EOI
}
