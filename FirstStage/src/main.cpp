#include <ncurses.h>
#include "../include/window.hpp"

int main() {

    Window window = Window(24,60);
    window.startWindow();

    return 0;
}


//g++ main.cpp -c -o main.o -lncurses -std=c++17 -Wall -ggdb
//g++ main.o -o main -lncurses -std=c++17 -Wall -ggdb
