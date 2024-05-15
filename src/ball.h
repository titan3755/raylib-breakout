#pragma once
#include <raylib.h>

class Ball {
public:
    Ball(int x, int y, int radius, int xVelocity, int yVelocity, Color color);
    void move();
    void draw();
    void setX(int x);
    void setY(int y);
    void setXVelocity(int xVelocity);
    void setYVelocity(int yVelocity);
    void checkBoundaries(int screenX, int screenY);
    void deflect(int deflectionSide, int screenX, int screenY);
    int getX();
    int getY();
    int getXVelocity();
    int getYVelocity();
    int getRadius();
    Color getColor();
    int getLives();
    void setLives(int lives);
    void setGpause(int gpause);
    int getGpause();
private:
    int radius;
    Color color;
    int x;
    int y;
    int xVelocity;
    int yVelocity;
    int lives = 3;
    int gpause = 0;
};