#include "include/interrupts.h"
#include "include/io.h"
#include "include/keyboard.h"
#include "include/terminal.h"

void interrupts_init() {
  pic_init();
  idt_init();
}

#define idt_entries 256

idt_entry_t idt[idt_entries];
idt_ptr_t idtp;

void idt_set(int index, uint32_t base, uint16_t selector, uint8_t type_attr) {
  idt[index].offset_low = base & 0xffff;
  idt[index].offset_high = (base >> 16) & 0xffff;
  idt[index].selector = selector;
  idt[index].zero = 0;
  idt[index].type_attr = type_attr;
}

void idt_init() {
  idtp.limit = (sizeof(idt_entry_t) * idt_entries) - 1;
  idtp.base = (uintptr_t)&idt;

  idt_set(33, (uintptr_t)keyboard_interrupt, 0x08, 0x8e);

  asm volatile("lidt %0" : : "m"(idtp));
  asm volatile("sti");
}

#define PIC1 0x20
#define PIC2 0xa0
#define PIC1_COMMAND PIC1
#define PIC1_DATA (PIC1 + 1)
#define PIC2_COMMAND PIC2
#define PIC2_DATA (PIC2 + 1)
#define PIC_EOI 0x20

void pic_init() {
  // Send the ICW1 command to the PICs
  outb(PIC1_COMMAND, 0x11);
  outb(PIC2_COMMAND, 0x11);

  // Set the base addresses of the PICs
  outb(PIC1_DATA, 0x20);
  outb(PIC2_DATA, 0x28);

  // Set the master/slave relationships between the PICs
  outb(PIC1_DATA, 0x04);
  outb(PIC2_DATA, 0x02);

  // Enable 80x86 mode on the PICs
  outb(PIC1_DATA, 0x01);
  outb(PIC2_DATA, 0x01);

  // Set the mask bytes of the PICs
  outb(PIC1_DATA, 0xFD);
  outb(PIC2_DATA, 0xFF);
}

void send_eoi(uint8_t irq) {
  if (irq >= 8)
    outb(PIC2_COMMAND, PIC_EOI);

  outb(PIC1_COMMAND, PIC_EOI);
}

void keyboard_interrupt() {
  asm volatile("cli");
  keyboard_handle_input();
  send_eoi(1);
  asm volatile("sti");
}
