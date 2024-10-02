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
  idtp.base = (uint32_t)&idt;

  idt_set(33, (uint32_t)keyboard_interrupt, 0x08, 0x8e);

  asm volatile("lidt %0" : : "m"(idtp));
  asm volatile("sti");
}

#define pic1 0x20
#define pic2 0xa0
#define pic1_command pic1
#define pic1_data (pic1 + 1)
#define pic2_command pic2
#define pic2_data (pic2 + 1)

void pic_init() {
  outb(pic1_command, 0x11);
  outb(pic2_command, 0x11);

  outb(pic1_data, 0x20);
  outb(pic2_data, 0x28);

  outb(pic1_data, 0x04);
  outb(pic2_data, 0x02);

  outb(pic1_data, 0x01);
  outb(pic2_data, 0x01);

  outb(pic1_data, 0xFD);
  outb(pic2_data, 0xFF);
}

#define PIC_EOI 0x20

void send_eoi(uint8_t irq) {
  if (irq >= 8)
    outb(pic2_command, PIC_EOI);

  outb(pic1_command, PIC_EOI);
}

void keyboard_interrupt() {
  keyboard_handle_input();
  send_eoi(1);
  asm volatile("sti");
}
