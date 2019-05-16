#include "../include/window.hpp"
#include <unistd.h>

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
    for(int j = 0; j < 3; j++){
        for(int i = 3; i < 145; i++){
            drawCustomer(i);
            usleep(100000);
            if(i == 40)
                sleep(2);
            eraseCustomer(i);
        }
    }
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

   // for(int i = 40; i < 145; i = i + 4)
   //     drawCustomer(i);
}

void Window::drawCustomer(int x){
    mvwprintw(window, 16, x, "O");
    mvwprintw(window, 17, x, "|");
    mvwprintw(window, 17, x - 1, "/");
    mvwprintw(window, 17, x + 1, "\\");
    mvwprintw(window, 18, x, "A");
    wrefresh(window);
}

void Window::eraseCustomer(int x){
    mvwprintw(window, 16, x, " ");
    mvwprintw(window, 17, x, " ");
    mvwprintw(window, 17, x - 1, " ");
    mvwprintw(window, 17, x + 1, " ");
    mvwprintw(window, 18, x, " ");
    wrefresh(window);
}

void Window::drawVegetables(int startingPointX, std::vector<Vegetable> vegetables){
    switch(vegetables.size()){
        case 0:
            break;
        case 1:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 1);
            break;
        case 2:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 2);
            break;
        case 3:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 3);
            break;
        case 4:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 4);
            break;
        case 5:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 5);
            break;
        case 6:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 6);
            break;
        case 7:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 7);
            break;
        case 8:
            drawRow(startingPointX, 7, vegetableChar(vegetables[0].getVegetableType()), 8);
            break;
            
    }
}

void Window::drawRow(int startX, int startY, char * vegetable, int vegeNumber){
    for(int i = startX; i < vegeNumber; i++)
        mvwprintw(window, startY, i, vegetable);
}

char * Window::vegetableChar(int vegetable){
    switch(vegetable){
        case 0:
            return "C";
            break;
        case 1:
            return "X";
            break;
        case 2:
            return "S";
            break;
        case 3:
            return "Z";
            break;
        case 4:
            return "B";
            break;
        case 5:
            return "E";
            break;
        case 6:
            return "P";
            break;
        case 7:
            return "T";
            break;
        case 8:
            return "O";
            break;
        case 9:
            return "I";
            break;
        default:
            return "W";
            break;
    }
}

void Window::clearVegetables(int startingPointX){
    for(int i = startingPointX + 1; i < startingPointX + 12; i ++){
        for(int j = 7; j > 3; j--){
            mvwprintw(window, j, i, " ");
        }
    }
    wrefresh(window);
}