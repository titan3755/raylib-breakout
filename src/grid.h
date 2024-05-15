#pragma once
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
class BrickGrid {
public:
    BrickGrid(int rows, int columns, int brickWidth, int brickHeight, int padding, Color color);
    void draw();
    void checkCollision(int ballX, int ballY, int ballRadius, int ballXVelocity, int ballYVelocity, Ball *ball);
    void setBrick(int row, int column, bool value);
    bool getBrick(int row, int column);
    int getRows();
    int getColumns();
    int getBrickWidth();
    int getBrickHeight();
    int getPadding();
    Color getColor();
    int getScore();
    void setScore(int score);
    void resetGrid();
private:
    int rows;
    int columns;
    int brickWidth;
    int brickHeight;
    int padding;
    Color color;
    bool **bricks;
    int score = 0;
};
