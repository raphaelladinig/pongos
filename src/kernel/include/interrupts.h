#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

extern void (*timer)();
void interrupts_init();

typedef struct {
  uint16_t offset_low;
  uint16_t selector;
  uint8_t zero;
  uint8_t type_attr;
  uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
  uint16_t limit;
  uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void send_eoi(uint8_t irq);

void idt_set(int index, uint32_t base, uint16_t selector, uint8_t type_attr);

void idt_init();

void pic_init();

void send_EOI(uint8_t irq);

void keyboard_interrupt();

#endif
