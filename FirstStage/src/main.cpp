#include <ncurses.h>
#include "../include/window.hpp"

int main() {

    Window window = Window(18,45);
    window.startWindow();

    return 0;
}