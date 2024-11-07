#include "include/pong.h"
#include "include/timer.h"
#include "include/vga.h"

struct rectangle ball;
int velocity_x;
int velocity_y;
struct rectangle left_paddle;
struct rectangle right_paddle;

void move_ball(struct rectangle *ball) {
  erase_rectangle(ball);

  // Update ball position with velocity
  ball->x += velocity_x;
  ball->y += velocity_y;

  // Check for collision with bounds and reverse direction if needed
  if (ball->x <= 0 || ball->x >= 300 - ball->width) {
    velocity_x = -velocity_x;
  }
  if (ball->y <= 0 || ball->y >= 200 - ball->width) {
    velocity_y = -velocity_y;
  }

  draw_rectangle(ball);
}

void timer_tick() { move_ball(&ball); };

void pong_init() {
  ball = (struct rectangle){160, 100, 5, 5, 0x0F};
  velocity_x = 2;
  velocity_y = 2;
  left_paddle = (struct rectangle){0, 50, 50, 5, 0x0F};
  right_paddle = (struct rectangle){310, 50, 50, 5, 0x0F};
}
