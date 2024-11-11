#include "include/pong.h"
#include "include/interrupts.h"
#include "include/keyboard.h"
#include "include/terminal.h"
#include "include/vga.h"

struct rectangle ball;
int velocity_x;
int velocity_y;
struct rectangle left_paddle;
struct rectangle right_paddle;

void move_ball() {
  erase_rectangle(&ball);

  // Update ball position with velocity
  ball.x += velocity_x;
  ball.y += velocity_y;

  // Check for collision with bounds and reverse direction if needed
  if (ball.x <= 0 || ball.x >= 320 - ball.width) {
    velocity_x = -velocity_x;
    draw_rectangle(&ball);
    draw_rectangle(&left_paddle);
    draw_rectangle(&right_paddle);
  }
  if (ball.y <= 0 || ball.y >= 200 - ball.width) {
    velocity_y = -velocity_y;
  }

  draw_rectangle(&ball);
}

void move_paddle(struct rectangle *paddle, int direction) {
  erase_rectangle(paddle);

  // Update paddle position
  paddle->y += direction * 5;

  // Ensure paddle stays within bounds
  if (paddle->y < 0) {
    paddle->y = 0;
  } else if (paddle->y > 200 - paddle->height) {
    paddle->y = 200 - paddle->height;
  }

  draw_rectangle(paddle);
}

void check_collision() {
  // Check for collision with left paddle
  if (ball.x <= left_paddle.x + left_paddle.width &&
      ball.y + ball.height >= left_paddle.y &&
      ball.y <= left_paddle.y + left_paddle.height) {
    velocity_x = -velocity_x;
  }

  // Check for collision with right paddle
  if (ball.x + ball.width >= right_paddle.x &&
      ball.y + ball.height >= right_paddle.y &&
      ball.y <= right_paddle.y + right_paddle.height) {
    velocity_x = -velocity_x;
  }
}

void loop() {
  move_ball();
  check_collision();
}

void pong_handle_input() {
  char c = keyboard_get_input();
  if (c == NULL) {
    return;
  }

  if (c == 'w') {
    move_paddle(&left_paddle, -1);
  } else if (c == 's') {
    move_paddle(&left_paddle, 1);
  } else if (c == 'o') {
    move_paddle(&right_paddle, -1);
  } else if (c == 'l') {
    move_paddle(&right_paddle, 1);
  }
}

void pong_init() {
  terminal_deactivate();
  clear_screen();

  ball = (struct rectangle){160, 100, 5, 5, 0x0F};
  velocity_x = 2;
  velocity_y = 2;
  left_paddle = (struct rectangle){0, 50, 50, 5, 0x0F};
  right_paddle = (struct rectangle){310, 50, 50, 5, 0x0F};

  draw_rectangle(&ball);
  draw_rectangle(&left_paddle);
  draw_rectangle(&right_paddle);

  timer = loop;
  keyboard_handle_input = pong_handle_input;
}
