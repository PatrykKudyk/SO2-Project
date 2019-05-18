#include <ncurses.h>
#include "../include/window.hpp"
#include <ctime>

#include <iostream>

int main() {
    srand(time(NULL));
    Window window = Window(30,148);

    window.startWindow();

    std::cin.get();
    std::cin.get();

    return 0;
}