#include <raylib.h>
#include <string>
#include <ctime>
#include "ball.h"
#include "paddle.h"
#include "grid.h"
#include "text.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define BALL_RADIUS 10
#define BALL_COLOR WHITE
#define PADDLE_COLOR BLUE
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 10
#define LIVES 5

int randomNumberWithinRange(int min, int max) {
    if (GetRandomValue(0, 1) == 0) {
        return GetRandomValue(min, max) * (-1);
    } else {
        return GetRandomValue(min, max);
    }
}

void gameActions(Ball &ball, Paddle &paddle, BrickGrid &bgrid, bool &gameOn, bool &gameEnd, GameText &scoreText, GameText &gamePauseText, GameText &gameLivesText, bool &gameWon) {
    if(IsKeyDown(KEY_LEFT)) {
        paddle.setXVelocity(-12);
    } else if(IsKeyDown(KEY_RIGHT)) {
        paddle.setXVelocity(12);
    }
    BeginDrawing();
    ClearBackground(BLACK);
    ball.move();
    paddle.move();
    ball.checkBoundaries(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (ball.getGpause() == 1) {
        paddle.setX(SCREEN_WIDTH / 2);
        paddle.setXVelocity(0);
        ball.setXVelocity(0);
        ball.setYVelocity(0);
        ball.setX(SCREEN_WIDTH / 2);
        ball.setY(SCREEN_HEIGHT / 2);
        gamePauseText.setText(std::to_string(ball.getLives()) + " Lives Remaining! Press space to continue");
        gamePauseText.draw();
        EndDrawing();
        if (ball.getLives() == 0) {
            gameOn = false;
            gameEnd = true;
        }
        if (IsKeyPressed(KEY_SPACE)) {
            ball.setGpause(0);
            ball.setX(SCREEN_WIDTH / 2);
            ball.setY(SCREEN_HEIGHT / 2);
            ball.setXVelocity(randomNumberWithinRange(5, 8));
            ball.setYVelocity(randomNumberWithinRange(5, 8));
        }
    } else {
        paddle.checkBoundaries(SCREEN_WIDTH);
        paddle.checkCollision(ball.getX(), ball.getY(), ball.getRadius(), ball.getYVelocity(), &ball);
        bgrid.checkCollision(ball.getX(), ball.getY(), ball.getRadius(), ball.getXVelocity(), ball.getYVelocity(), &ball);
        gameLivesText.setText("Lives: " + std::to_string(ball.getLives()));
        scoreText.setText("Score: " + std::to_string(bgrid.getScore()));
        if (bgrid.getScore() == bgrid.getRows() * bgrid.getColumns()) {
            gameOn = false;
            gameEnd = true;
            gameWon = true;
        }
        ball.draw();
        bgrid.draw();
        paddle.draw();
        scoreText.draw();
        gameLivesText.draw();
        EndDrawing();
    }
}

void titleScreenActions(bool &titleScreen, bool &gameOn, bool &gameEnd, GameText &titleText) {
    BeginDrawing();
    ClearBackground(BLACK);
    titleText.draw();
    if (IsKeyPressed(KEY_ENTER)) {
        titleScreen = false;
        gameOn = true;
    }
    EndDrawing();
}

void gameoverScreenActions(bool &titleScreen, bool &gameOn, bool &gameEnd, GameText &gameoverText, GameText &gameoverRestartText, BrickGrid &bgrid, Ball &ball, Paddle &paddle, GameText &scoreText, bool &gameWon) {
    if (gameWon) {
        gameoverText.setText("You Won!");
        gameoverRestartText.setText("Press Enter to play again");
    } else {
        gameoverText.setText("You Lost!");
        gameoverRestartText.setText("Press Enter to restart");
    }
    BeginDrawing();
    ClearBackground(BLACK);
    gameoverText.draw();
    gameoverRestartText.draw();
    if (IsKeyPressed(KEY_ENTER)) {
        ball.setXVelocity(randomNumberWithinRange(5, 8));
        ball.setYVelocity(randomNumberWithinRange(5, 8));
        ball.setX(SCREEN_WIDTH / 2);
        ball.setY(SCREEN_HEIGHT / 2);
        paddle.setX(SCREEN_WIDTH / 2);
        bgrid.resetGrid();
        ball.setLives(LIVES);
        gameEnd = false;
        gameOn = true;
        ball.setGpause(0);
    }
    EndDrawing();
}

int main() {
    SetRandomSeed(time(0));
    bool titleScreen, gameOn, gameEnd, gameWon;
    titleScreen = true;
    gameOn = false;
    gameEnd = false;
    gameWon = false;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout Game");
    SetTargetFPS(80);
    Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_RADIUS, randomNumberWithinRange(5, 8), randomNumberWithinRange(5, 8), BALL_COLOR);
    ball.setLives(LIVES);
    Paddle paddle(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, PADDLE_WIDTH, PADDLE_HEIGHT, 0, PADDLE_COLOR);
    BrickGrid bgrid(5, 10, 70, 30, 10, RED);
    GameText titleText("Press Enter to Start", ((SCREEN_WIDTH / 2) - 125), SCREEN_HEIGHT / 2, 25, WHITE);
    GameText gameoverText("Game Over!", SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2, 25, WHITE);
    GameText gameoverRestartText("Press Enter for next round", SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2 + 50, 25, WHITE);
    GameText gamePauseText(std::to_string(ball.getLives()) + " Lives Remaining! Press space to continue", SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2, 15, WHITE);
    GameText gameLivesText("Lives: " + std::to_string(ball.getLives()), 10, 10 + 15, 12, YELLOW);
    GameText scoreText("Score: " + std::to_string(bgrid.getScore()), 10, 10, 12, YELLOW);
    while (!WindowShouldClose()) {
        if (titleScreen) {
            titleScreenActions(titleScreen, gameOn, gameEnd, titleText);
        }
        if (gameOn) {
            gameActions(ball, paddle, bgrid, gameOn, gameEnd, scoreText, gamePauseText, gameLivesText, gameWon);
        }
        if (gameEnd) {
            gameoverScreenActions(titleScreen, gameOn, gameEnd, gameoverText, gameoverRestartText, bgrid, ball, paddle, scoreText, gameWon);
        }
    }
    CloseWindow();
    return 0;
}
