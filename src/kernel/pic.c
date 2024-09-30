#include "include/pic.h"
#include "include/io.h"

#define PIC1_COMMAND 0x20  // Master PIC command port
#define PIC1_DATA    0x21  // Master PIC data port
#define PIC2_COMMAND 0xA0  // Slave PIC command port
#define PIC2_DATA    0xA1  // Slave PIC data port

void pic_init() {
    // Start the initialization sequence
    outb(PIC1_COMMAND, 0x11); // Begin initialization (ICW1)
    outb(PIC2_COMMAND, 0x11); // Begin initialization (ICW1)

    // Set the vector offset for the master and slave PIC
    outb(PIC1_DATA, 0x20);    // Set vector offset for master PIC
    outb(PIC2_DATA, 0x28);    // Set vector offset for slave PIC

    // Configure the PIC to work in cascade mode
    outb(PIC1_DATA, 0x04);    // Tell master that there is a slave PIC at IRQ2
    outb(PIC2_DATA, 0x02);    // Tell slave its cascade identity

    // Set the operating mode
    outb(PIC1_DATA, 0x01);    // 8086/88 (MCS-80) mode
    outb(PIC2_DATA, 0x01);    // 8086/88 (MCS-80) mode

    // Unmask all IRQs (enable all interrupts)
    outb(PIC1_DATA, 0xFF);    // Mask all interrupts on master PIC
    outb(PIC2_DATA, 0xFF);    // Mask all interrupts on slave PIC
}
