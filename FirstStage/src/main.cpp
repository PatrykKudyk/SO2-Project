#include <iostream>
#include <thread>
#include <ncurses.h>
#include "../include/window.hpp"
#include <thread>

int main() {

    nodelay(stdscr, NULL);
    Window window = Window();
    window.startWindow();

    return 0;
}


//g++ main.cpp -c -o main.o -lncurses -std=c++17 -Wall -ggdb
//g++ main.o -o main -lncurses -std=c++17 -Wall -ggdb
