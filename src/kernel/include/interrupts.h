#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t  zero;
    uint8_t  type_attr;
    uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void idt_set(int index, uint32_t base, uint16_t selector,
                   uint8_t type_attr);

void idt_init();

void pic_init();

void interrupts_init();

void divide_by_zero_interrupt();

void keyboard_interrupt();

#endif
