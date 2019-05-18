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
    Vegetable vegetable(0);
    std::vector<Vegetable> vegeVec;  
    vegetablesVec.push_back(vegeVec);

    for(int i = 0; i < 60; i++){
        vegetablesVec[0].push_back(vegetable);
        clearVegetables(5);
        drawVegetables(5,vegetablesVec[0]);
        usleep(200000);
    }

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
    if(vegetables.size() > 0){
        switch(vegetables[0].getVegetableType()){
            case 0:
                drawSomeVegetables(startingPointX, 7, 'Q', vegetables.size());
                break;
            case 1:
                drawSomeVegetables(startingPointX, 7, 'L', vegetables.size());
                break;
            case 2:
                drawSomeVegetables(startingPointX, 7, 'P', vegetables.size());
                break;
            case 3:
                drawSomeVegetables(startingPointX, 7, 'U', vegetables.size());
                break;
            case 4:
                drawSomeVegetables(startingPointX, 7, 'K', vegetables.size());
                break;
            case 5:
                drawSomeVegetables(startingPointX, 7, 'C', vegetables.size());
                break;
            case 6:
                drawSomeVegetables(startingPointX, 7, 'D', vegetables.size());
                break;
            case 7:
                drawSomeVegetables(startingPointX, 7, 'G', vegetables.size());
                break;
            case 8:
                drawSomeVegetables(startingPointX, 7, 'J', vegetables.size());
                break;
            case 9:
                drawSomeVegetables(startingPointX, 7, 'V', vegetables.size());
                break;        
            default:
                break;
        }
    }
}

void Window::drawSomeVegetables(int startX, int startY, char vegetable, int vegeNumber){
    if(vegeNumber <= 12)
        drawRow(startX, startY, vegetable, vegeNumber);
    else if(vegeNumber > 12 && vegeNumber <= 24){
        int lastRow = vegeNumber - 12;
        drawRow(startX, startY, vegetable, 12);
        drawRow(startX, startY - 1, vegetable, lastRow);
    } else if(vegeNumber > 24 && vegeNumber <= 36){
        int lastRow = vegeNumber - 24;
        drawRow(startX, startY, vegetable, 12);
        drawRow(startX, startY - 1, vegetable, 12);
        drawRow(startX, startY - 2, vegetable, lastRow);
    } else if(vegeNumber > 36 && vegeNumber <= 48){
        int lastRow = vegeNumber - 36;
        drawRow(startX, startY, vegetable, 12);
        drawRow(startX, startY - 1, vegetable, 12);
        drawRow(startX, startY - 2, vegetable, 12);
        drawRow(startX, startY - 3, vegetable, lastRow);        
    } else if(vegeNumber > 48 && vegeNumber <= 60){
        int lastRow = vegeNumber - 48;
        drawRow(startX, startY, vegetable, 12);
        drawRow(startX, startY - 1, vegetable, 12);
        drawRow(startX, startY - 2, vegetable, 12);
        drawRow(startX, startY - 3, vegetable, 12);
        drawRow(startX, startY - 4, vegetable, lastRow);        
    }
    wrefresh(window);
}

void Window::drawRow(int startX, int startY, char vegetableChar, int vegeNumber){
    const char * vegetable = &vegetableChar;
    for(int i = startX; i < vegeNumber + startX; i++)
        mvwprintw(window, startY, i, vegetable);
}

void Window::clearVegetables(int startingPointX){
    for(int i = startingPointX; i < startingPointX + 12; i++){
        for(int j = 7; j > 3; j--){
            mvwprintw(window, j, i, " ");
        }
    }
    wrefresh(window);
}