#pragma once
#include <ncurses.h>
#include <vector>
#include "../include/vegetable.hpp"

class Window{
    private:
    WINDOW *window;
    int width;
    int height;
    std::vector<std::vector<Vegetable>> vegetables;

    public:
    Window(int height, int width);
    ~Window();
    void startWindow();
    void baseDraw();
    void drawCustomer(int x);
    void eraseCustomer(int x);
    void drawVegetables(int startingPointX, std::vector<Vegetable> vegetables);
    void drawRow(int startX, int startY, char * vegetable, int vegeNumber);
    char * vegetableChar(int vegetable);
    void clearVegetables(int startingPointX);
};