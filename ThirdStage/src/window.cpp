#include "../include/window.hpp"


Window::Window(int height, int width){
    this->height = height;
    this->width = width;
    initscr();      //inicjuje ncurses
    curs_set(FALSE);    //nie wyswietla kursora
    noecho();       //nie wyswietla inputu
    nodelay(stdscr,TRUE);      //nie czeka na getchar, tylko ogarnia go w tle
   // cbreak();       //pozwala na wyjscie z programu przy pomocyh "Ctlr+C"
    this->window = newwin(height, width, 0, 0);    //inicjalizuje okno

    refresh(); 
    box(window, 0,0);   //inicjalizuje ramke dookoła okna
    wrefresh(window);
}

Window::~Window(){

    endwin();       //kończę korzystanie z ncurses
}

void Window::startWindow(){
    baseDraw();    
}

void Window::baseDraw(){
    //pionowe ściany półek
    for(int j = 3; j < 144; j = j + 14){
        for(int i = 3; i < 8; i++)
            mvwprintw(window, i, j, "|");
    }

    //pozioma ściana półek
    for(int i = 3; i < 144; i++)
        mvwprintw(window, 8, i, "-");

    //lada
    mvwprintw(window, 14, 3, "|");
    mvwprintw(window, 14, 144, "|");
    for(int i = 3; i < 145; i++){
        mvwprintw(window, 13, i, "-");
        mvwprintw(window, 15, i, "-");
    }

    //sprzedawca
    mvwprintw(window, 10, 40, "O");
    mvwprintw(window, 11, 40, "|");
    mvwprintw(window, 11, 39, "/");
    mvwprintw(window, 11, 41, "\\");
    mvwprintw(window, 12, 40, "A");
    
    wrefresh(window);

    for(int i = 40; i < 145; i = i + 4)
        drawCustomer(i);
}

void Window::drawCustomer(int x){
    mvwprintw(window, 16, x, "O");
    mvwprintw(window, 17, x, "|");
    mvwprintw(window, 17, x - 1, "/");
    mvwprintw(window, 17, x + 1, "\\");
    mvwprintw(window, 18, x, "A");
    wrefresh(window);
}