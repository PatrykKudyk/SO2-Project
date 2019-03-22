#include "../include/window.hpp"

Window::Window(){
    initscr();

    //noecho();
    cbreak();
    this->window = newwin(15, 40, 0, 5);

    refresh();
    box(window, 0,0);
    wrefresh(window);
    getch();

    char newball = getch();
        if(newball == 'q'){
            balls.push_back(new Ball(7,20,1));
        }

        mvwprintw(window,balls[0]->getPosY(),balls[0]->getPosX(), "o");
        wrefresh(window);

}

Window::~Window(){

    endwin();
}

void Window::startWindow(){

    start_color();
    char newball;
    init_pair(1, COLOR_RED, COLOR_BLACK);
    balls.push_back(new Ball(10,20,1));
    wrefresh(window);
    do{
        newball = getch();
        if(newball == 'q'){
            balls.push_back(new Ball(7,20,1));
        }

        mvwprintw(window,balls[0]->getPosY(),balls[0]->getPosX(), "o");
        wrefresh(window);

        //displayBalls();

    }while(true);
}

void Window::displayBalls(){
    
    for(int i = 0; i < balls.size(); i++){
        attron(A_BOLD);
        attron(COLOR_PAIR(balls[i]->getColor()));
        mvwprintw(window,balls[i]->getPosY(),balls[i]->getPosX(), "o");
        wrefresh(window);
    }
}
