#include <ncurses.h>
#include "../include/window.hpp"

int main() {

    Window window = Window(25,74);
    window.startWindow();

    return 0;
}