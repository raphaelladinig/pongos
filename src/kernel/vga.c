#include "include/vga.h"

#define VGA_MODE 0x13
#define VGA_WIDTH 320
#define VGA_HEIGHT 200

void fill_screen(unsigned char color) {
  unsigned char *video_memory = (unsigned char *)0xA0000;
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    video_memory[i] = color;
  }
}

void draw_rectangle(struct rectangle *rectangle) {
  unsigned char *video_memory = (unsigned char *)0xA0000;

  for (int i = 0; i < rectangle->height; i++) {
    for (int j = 0; j < rectangle->width; j++) {
      int pixel_position = (rectangle->y + i) * VGA_WIDTH + (rectangle->x + j);
      video_memory[pixel_position] = rectangle->color;
    }
  }
}

void erase_rectangle(struct rectangle *rectangle) {
  draw_rectangle(&(struct rectangle){rectangle->x, rectangle->y,
                                     rectangle->width, rectangle->height, 0});
}

void clear_screen() {
  unsigned char *video_memory = (unsigned char *)0xA0000;
  for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    video_memory[i] = 0x00;
  }
}

void switch_to_video_mode() {
  asm volatile(
    "cli\n"                      // Disable interrupts
    "mov %cr0, %eax\n"           // Move CR0 to EAX
    "and $0x7FFFFFFE, %eax\n"    // Clear PE bit (bit 0) to switch to real mode
    "mov %eax, %cr0\n"           // Move EAX back to CR0
    "jmp 1f\n"                   // Far jump to flush the pipeline
    "1:\n"
    "mov $0x13, %ax\n"           // Set video mode 0x13
    "int $0x10\n"                // BIOS interrupt
    "mov %cr0, %eax\n"           // Move CR0 to EAX
    "or $0x1, %eax\n"            // Set PE bit (bit 0) to switch back to protected mode
    "mov %eax, %cr0\n"           // Move EAX back to CR0
    "jmp 2f\n"                   // Far jump to flush the pipeline
    "2:\n"
    "sti\n"                      // Enable interrupts
  );
  clear_screen();
}

void switch_to_text_mode() {
  asm volatile("mov $0x03, %ax\n"
               "int $0x10\n");
}
