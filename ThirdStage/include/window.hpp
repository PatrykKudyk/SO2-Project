#pragma once
#include <ncurses.h>

class Window{
    private:
    WINDOW *window;
    int width;
    int height;

    public:
    Window(int height, int width);
    ~Window();
    void startWindow();
    void baseDraw();
    void drawCustomer(int x);
};