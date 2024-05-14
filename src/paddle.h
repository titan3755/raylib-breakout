#pragma once
#include <raylib.h>
#include "ball.h"
class Paddle {
public:
    Paddle(int x, int y, int width, int height, int xVelocity, Color color);
    void move();
    void draw();
    void setX(int x);
    void setXVelocity(int xVelocity);
    void checkBoundaries(int screenX);
    void checkCollision(int ballX, int ballY, int ballRadius, int ballYVelocity, Ball *ball);
    int getX();
    int getY();
    int getXVelocity();
    int getWidth();
    int getHeight();
    Color getColor();
private:
    int x;
    int y;
    int width;
    int height;
    int xVelocity;
    Color color;
};