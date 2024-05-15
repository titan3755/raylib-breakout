#include "text.h"

GameText::GameText(std::string text, int x, int y, int fontSize, Color color) {
    this->text = text;
    this->x = x;
    this->y = y;
    this->fontSize = fontSize;
    this->color = color;
}

void GameText::draw() {
    DrawText(text.c_str(), x, y, fontSize, color);
}

void GameText::setText(std::string text) {
    this->text = text;
}

void GameText::setX(int x) {
    this->x = x;
}

void GameText::setY(int y) {
    this->y = y;
}

void GameText::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}

void GameText::setColor(Color color) {
    this->color = color;
}

std::string GameText::getText() {
    return text;
}

int GameText::getX() {
    return x;
}

int GameText::getY() {
    return y;
}

int GameText::getFontSize() {
    return fontSize;
}

Color GameText::getColor() {
    return color;
}

