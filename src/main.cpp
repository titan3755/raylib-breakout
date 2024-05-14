#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "grid.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define BALL_RADIUS 10
#define BALL_COLOR WHITE
#define PADDLE_COLOR BLUE
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 10


void gameActions(Ball &ball, Paddle &paddle, BrickGrid &bgrid) {
    if(IsKeyDown(KEY_LEFT)) {
        paddle.setXVelocity(-5);
    } else if(IsKeyDown(KEY_RIGHT)) {
        paddle.setXVelocity(5);
    }
    ball.move();
    paddle.move();
    ball.checkBoundaries(SCREEN_WIDTH, SCREEN_HEIGHT);
    paddle.checkBoundaries(SCREEN_WIDTH);
    paddle.checkCollision(ball.getX(), ball.getY(), ball.getRadius(), ball.getYVelocity(), &ball);
    bgrid.checkCollision(ball.getX(), ball.getY(), ball.getRadius(), ball.getXVelocity(), ball.getYVelocity(), &ball);
    ball.draw();
    bgrid.draw();
    paddle.draw();
}

int main() {
    int ballx = SCREEN_WIDTH / 2;
    int bally = SCREEN_HEIGHT / 2;
    bool titleScreen, gameOn, gameEnd;
    titleScreen = true;
    gameOn = false;
    gameEnd = false;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout Game");
    SetTargetFPS(80);
    Ball ball(ballx, bally, BALL_RADIUS, 5, 5, BALL_COLOR);
    Paddle paddle(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, PADDLE_WIDTH, PADDLE_HEIGHT, 0, PADDLE_COLOR);
    BrickGrid bgrid(5, 10, 70, 30, 10, RED);
    while (!WindowShouldClose()) {
        if (titleScreen) {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Press Enter to Start", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, WHITE);
            if (IsKeyPressed(KEY_ENTER)) {
                titleScreen = false;
                gameOn = true;
            }
            EndDrawing();
        }
        if (gameOn) {
            BeginDrawing();
            ClearBackground(BLACK);
            gameActions(ball, paddle, bgrid);
            EndDrawing();
        }
        if (gameEnd) {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Game Over!", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, WHITE);
            DrawText("Press Enter to Restart", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50, 25, WHITE);
            if (IsKeyPressed(KEY_ENTER)) {
                gameEnd = false;
                gameOn = true;
            }
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}
