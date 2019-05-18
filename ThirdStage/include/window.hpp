#pragma once
#include <ncurses.h>
#include <vector>
#include "../include/vegetable.hpp"

class Window{
    private:
    WINDOW *window;
    int width;
    int height;
    std::vector<std::vector<Vegetable>> vegetablesVec;

    public:
    Window(int height, int width);
    ~Window();
    void createVegetableVectors();
    void startWindow();
    void baseDraw();
    void drawCustomer(int x);
    void eraseCustomer(int x);
    void drawShelfs();
    void drawVegetables(int startingPointX, std::vector<Vegetable> vegetables);
    void drawSomeVegetables(int startX, int startY, char vegetable, int vegeNumber);
    void drawRow(int startX, int startY, char vegetableChar, int vegeNumber);
    void clearVegetables(int startingPointX);
};