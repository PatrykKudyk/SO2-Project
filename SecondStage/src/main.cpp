#include <ncurses.h>
#include "../include/window.hpp"

int main() {

    Window window = Window(24,75);
    window.startWindow();

    return 0;
}