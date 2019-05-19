#include "../include/window.hpp"
#include <unistd.h>

Window::Window(int height, int width){
    this->height = height;
    this->width = width;
    this->symbol = 'o';
    createVegetableVectors();
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

void Window::createVegetableVectors(){
    std::vector<Vegetable> vegeVec; 
    for(int i = 0; i < 10; i++)
        vegetablesVec.push_back(vegeVec);
    Vegetable vegetable(0);
    for(int i = 0; i < 10; i++){
        vegetable.setVegetableType(i);
        for(int j = 0; j < 55; j++){
            vegetablesVec[i].push_back(vegetable);
        }
    }
}

void Window::startWindow(){
    baseDraw();
    drawShelfs();
    std::vector<std::thread> threadVect;
    int i = 0;
    do{
        Customer customer;
        customersVect.push_back(customer);
        threadsOnCheck.push_back(true);
        threadVect.push_back(std::thread([&](){useCustomerWithThreads(i);}));
        sleep(2);
        for(int j = 0; j < threadsOnCheck.size(); j++){
            if(!threadsOnCheck[j])
                if(threadVect[j].joinable())
                    threadVect[j].join();
        }
        symbol = getch();
        i++;
    }while(symbol != 'q');


    for(auto& t : threadVect){
        if(t.joinable())
            t.join();
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

void Window::drawShelfs(){
    for(int i = 0, j = 5; i < 10; i++, j = j + 14){
        clearVegetables(j);
        drawVegetables(j,vegetablesVec[i]);
    }
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
    if(vegeNumber <= 11)
        drawRow(startX, startY, vegetable, vegeNumber);
    else if(vegeNumber > 11 && vegeNumber <= 22){
        int lastRow = vegeNumber - 11;
        drawRow(startX, startY, vegetable, 11);
        drawRow(startX, startY - 1, vegetable, lastRow);
    } else if(vegeNumber > 22 && vegeNumber <= 33){
        int lastRow = vegeNumber - 22;
        drawRow(startX, startY, vegetable, 11);
        drawRow(startX, startY - 1, vegetable, 11);
        drawRow(startX, startY - 2, vegetable, lastRow);
    } else if(vegeNumber > 33 && vegeNumber <= 44){
        int lastRow = vegeNumber - 33;
        drawRow(startX, startY, vegetable, 11);
        drawRow(startX, startY - 1, vegetable, 11);
        drawRow(startX, startY - 2, vegetable, 11);
        drawRow(startX, startY - 3, vegetable, lastRow);        
    } else if(vegeNumber > 44 && vegeNumber <= 55){
        int lastRow = vegeNumber - 44;
        drawRow(startX, startY, vegetable, 11);
        drawRow(startX, startY - 1, vegetable, 11);
        drawRow(startX, startY - 2, vegetable, 11);
        drawRow(startX, startY - 3, vegetable, 11);
        drawRow(startX, startY - 4, vegetable, lastRow);        
    }
    wrefresh(window);
}

void Window::drawRow(int startX, int startY, char vegetableChar, int vegeNumber){
    const char * vegetable = new char(vegetableChar);
    for(int i = startX; i < vegeNumber + startX; i++)
        mvwprintw(window, startY, i, vegetable);
}

void Window::clearVegetables(int startingPointX){
    for(int i = startingPointX; i < startingPointX + 12; i++){
        for(int j = 7; j >= 3; j--){
            mvwprintw(window, j, i, " ");
        }
    }
    wrefresh(window);
}

void Window::useCustomerWithThreads(int threadId){
    while(threadsOnCheck[threadId]){

        if(symbol == 'q'){
            break;
        }
    
        if(customersVect[threadId]->getPositionX() >= 3){
    
        }
        else{
            threadsOnCheck[threadId] = false;
        }  
    }
}