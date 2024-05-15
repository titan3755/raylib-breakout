#pragma once
#include <raylib.h>
#include <string>

class GameText {
public:
    GameText(std::string text, int x, int y, int fontSize, Color color);
    void draw();
    void setText(std::string text);
    void setX(int x);
    void setY(int y);
    void setFontSize(int fontSize);
    void setColor(Color color);
    std::string getText();
    int getX();
    int getY();
    int getFontSize();
    Color getColor();
private:
    std::string text;
    int x;
    int y;
    int fontSize;
    Color color;
};