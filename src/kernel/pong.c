#include "include/pong.h"
#include "include/timer.h"
#include "include/vga.h"

struct paddle {
  int x;
  int y;
  int height;
  int width;
};

struct ball {
  int x;
  int y;
  int width;
};

struct ball ball = {160, 100, 5};

struct paddle left_paddle = {0, 50, 50, 5};
struct paddle right_paddle = {310, 50, 50, 5};

void draw_paddle(struct paddle paddle) {
  draw_rectangle(paddle.x, paddle.y, paddle.width, paddle.height, 0x0F);
}

void draw_ball(struct ball ball) {
  draw_rectangle(ball.x, ball.y, ball.width, ball.width, 0x0F);
}

void erase_ball(struct ball ball) {
  draw_rectangle(ball.x, ball.y, ball.width, ball.width, 0);
}

void move_ball(struct ball *ball) {
  erase_ball(*ball);

  ball->x += 2;
  ball->y += 2;

  if (ball->x <= 0 || ball->x + ball->width >= 320) {
    ball->x -= 2;
  }

  if (ball->y <= 0 || ball->y + ball->width >= 200) {
    ball->y -= 2;
  }

  draw_ball(*ball);
}

void timer_tick() { move_ball(&ball); };

void pong_init() {

  draw_paddle(left_paddle);
  draw_paddle(right_paddle);

  draw_ball(ball);
}
