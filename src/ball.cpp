#include "ball.h"

Ball::Ball(int x, int y, int radius, int xVelocity, int yVelocity, Color color) {
    this->x = x;
    this->y = y;
    this->xVelocity = xVelocity;
    this->yVelocity = yVelocity;
    this->radius = radius;
    this->color = color;
}

void Ball::move() {
    x += xVelocity;
    y += yVelocity;
}

void Ball::draw() {
    DrawCircle(x, y, radius, color);
}

void Ball::setX(int x) {
    this->x = x;
}

void Ball::setY(int y) {
    this->y = y;
}

void Ball::setXVelocity(int xVelocity) {
    this->xVelocity = xVelocity;
}

void Ball::setYVelocity(int yVelocity) {
    this->yVelocity = yVelocity;
}

void Ball::deflect(int deflectionSide, int screenX, int screenY) {
    if (deflectionSide == 0)
        xVelocity = -xVelocity;
    else if (deflectionSide == 1)
        yVelocity = -yVelocity;
}

void Ball::checkBoundaries(int screenX, int screenY) {
    if (x <= 0 || x >= screenX) {
        deflect(0, 0, 0);
    }
    if (y <= 0) {
        deflect(1, 0, 0);
    }
    if (y >= screenY) {
        lives--;
        gpause = 1;
    }
}

int Ball::getX() {
    return x;
}

int Ball::getY() {
    return y;
}

int Ball::getXVelocity() {
    return xVelocity;
}

int Ball::getYVelocity() {
    return yVelocity;
}

int Ball::getRadius() {
    return radius;
}

Color Ball::getColor() {
    return color;
}

int Ball::getLives() {
    return lives;
}

void Ball::setLives(int lives) {
    this->lives = lives;
}

void Ball::setGpause(int gpause) {
    this->gpause = gpause;
}   

int Ball::getGpause() {
    return gpause;
}