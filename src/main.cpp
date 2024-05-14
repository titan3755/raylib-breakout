#include <raylib.h>
#include "ball.h"
#include "paddle.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define BALL_RADIUS 10
#define BALL_COLOR WHITE
#define PADDLE_COLOR BLUE
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 10

int main() {
    int ballx = SCREEN_WIDTH / 2;
    int bally = SCREEN_HEIGHT / 2;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout Game");
    SetTargetFPS(80);
    Ball ball(ballx, bally, BALL_RADIUS, 5, 5, BALL_COLOR);
    Paddle paddle(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, PADDLE_WIDTH, PADDLE_HEIGHT, 0, PADDLE_COLOR);
    while (!WindowShouldClose()) {
        if(IsKeyDown(KEY_LEFT)) {
            paddle.setXVelocity(-5);
        } else if(IsKeyDown(KEY_RIGHT)) {
            paddle.setXVelocity(5);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        ball.move();
        paddle.move();
        ball.checkBoundaries(SCREEN_WIDTH, SCREEN_HEIGHT);
        paddle.checkBoundaries(SCREEN_WIDTH);
        paddle.checkCollision(ball.getX(), ball.getY(), ball.getRadius(), ball.getYVelocity(), &ball);
        ball.draw();
        paddle.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}