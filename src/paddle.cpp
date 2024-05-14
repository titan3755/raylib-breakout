#include "paddle.h"

Paddle::Paddle(int x, int y, int width, int height, int xVelocity, Color color) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xVelocity = xVelocity;
    this->color = color;
}

void Paddle::move() {
    x += xVelocity;
}

void Paddle::draw() {
    DrawRectangle(x, y, width, height, color);
}

void Paddle::setX(int x) {
    this->x = x;
}

void Paddle::setXVelocity(int xVelocity) {
    this->xVelocity = xVelocity;
}

void Paddle::checkBoundaries(int screenX) {
    if (x <= 0) {
        xVelocity = -xVelocity;
        x = 0;
    } else if (x + width >= screenX) {
        xVelocity = -xVelocity;
        x = screenX - width;
    }
}

void Paddle::checkCollision(int ballX, int ballY, int ballRadius, int ballYVelocity, Ball *ball) {
    if (ballX + ballRadius >= x && ballX - ballRadius <= x + width && ballY + ballRadius >= y && ballY - ballRadius <= y + height) {
        if (ballYVelocity > 0) {
            ball->setYVelocity(-ballYVelocity);
        }
    }
}

int Paddle::getX() {
    return x;
}

int Paddle::getY() {
    return y;
}

int Paddle::getXVelocity() {
    return xVelocity;
}

int Paddle::getWidth() {
    return width;
}

int Paddle::getHeight() {
    return height;
}

Color Paddle::getColor() {
    return color;
}