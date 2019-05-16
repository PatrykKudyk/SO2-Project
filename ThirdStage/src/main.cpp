#include <ncurses.h>
#include "../include/window.hpp"


#include <iostream>

int main() {

    Window window = Window(30,148);

    window.startWindow();

    std::cin.get();
    std::cin.get();

    return 0;
}