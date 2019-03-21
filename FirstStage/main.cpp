#include <iostream>
#include <ncurses.h>

int main() {

    initscr();

    refresh();

    printw("Hello World!");

    getch();

    endwin();


    return 0;
}