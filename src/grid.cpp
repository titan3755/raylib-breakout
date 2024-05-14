#include "grid.h"

BrickGrid::BrickGrid(int rows, int columns, int brickWidth, int brickHeight, int padding, Color color) {
    this->rows = rows;
    this->columns = columns;
    this->brickWidth = brickWidth;
    this->brickHeight = brickHeight;
    this->padding = padding;
    this->color = color;
    bricks = new bool*[rows];
    for (int i = 0; i < rows; i++) {
        bricks[i] = new bool[columns];
        for (int j = 0; j < columns; j++) {
            bricks[i][j] = true;
        }
    }
}

void BrickGrid::draw() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (bricks[i][j]) {
                DrawRectangle(j * (brickWidth + padding), i * (brickHeight + padding), brickWidth, brickHeight, color);
            }
        }
    }
}

void BrickGrid::checkCollision(int ballX, int ballY, int ballRadius, int ballXVelocity, int ballYVelocity, Ball *ball) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (bricks[i][j]) {
                if (ballX + ballRadius >= j * (brickWidth + padding) && ballX - ballRadius <= j * (brickWidth + padding) + brickWidth && ballY + ballRadius >= i * (brickHeight + padding) && ballY - ballRadius <= i * (brickHeight + padding) + brickHeight) {
                    ball->deflect(0, j * (brickWidth + padding) + brickWidth, i * (brickHeight + padding) + brickHeight);
                    bricks[i][j] = false;
                }
            }
        }
    }
}

void BrickGrid::setBrick(int row, int column, bool value) {
    bricks[row][column] = value;
}

bool BrickGrid::getBrick(int row, int column) {
    return bricks[row][column];
}

int BrickGrid::getRows() {
    return rows;
}

int BrickGrid::getColumns() {
    return columns;
}

int BrickGrid::getBrickWidth() {
    return brickWidth;
}

int BrickGrid::getBrickHeight() {
    return brickHeight;
}

int BrickGrid::getPadding() {
    return padding;
}

Color BrickGrid::getColor() {
    return color;
}
