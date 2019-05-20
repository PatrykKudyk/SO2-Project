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
    //std::thread delivery([&](){deliveryThread();});
    int i = 0;
    do{
        customersVect.push_back(new Customer(144));
        threadsOnCheck.push_back(true);
        threadVect.push_back(std::thread([&](){useCustomerWithThreads(i);}));
        sleep(1);
        for(long unsigned int j = 0; j < threadsOnCheck.size(); j++){
            if(!threadsOnCheck[j])
                if(threadVect[j].joinable())
                    threadVect[j].join();
        }
        symbol = getch();
        i++;
        mvwprintw(window,11,144,"%i ", i%15);
        wrefresh(window);
        if((i%15) == 0){
            supplyDelivery();
            drawShelfs();
        }

    }while(symbol != 'q');

    //delivery.join();
    for(auto& t : threadVect){
        if(t.joinable())
            t.join();
    }
}

void Window::baseDraw(){
    drawMutex.lock();
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

    drawMutex.unlock();
    wrefresh(window);

   // for(int i = 40; i < 145; i = i + 4)
   //     drawCustomer(i);
}

void Window::drawCustomer(int customerId){
    int x = customersVect[customerId]->getPositionX();
    drawMutex.lock();
    mvwprintw(window, 16, x, "O");
    mvwprintw(window, 17, x, "|");
    mvwprintw(window, 17, x - 1, "/");
    mvwprintw(window, 17, x + 1, "\\");
    mvwprintw(window, 18, x, "A");
    drawMutex.unlock();
    wrefresh(window);
}

void Window::eraseCustomer(int customerId){
    int x = customersVect[customerId]->getPositionX();
    drawMutex.lock();
    mvwprintw(window, 16, x, " ");
    mvwprintw(window, 17, x, " ");
    mvwprintw(window, 17, x - 1, " ");
    mvwprintw(window, 17, x + 1, " ");
    mvwprintw(window, 18, x, " ");
    drawMutex.unlock();
    wrefresh(window);
}

void Window::drawShelfs(){
    drawMutex.lock();
    for(int i = 0, j = 5; i < 10; i++, j = j + 14){
        clearVegetables(j);
        drawVegetables(j,vegetablesVec[i]);
    }
    drawMutex.unlock();
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

void Window::deliveryThread(){
    do{
        sleep(10);
        for(int i = 3; i < 145; i++){
            if(i == 40){
                usleep(1000000);
                supplyDelivery();
                //drawShelfs();
            }
            eraseDelivery(i - 1);
            drawDelivery(i);
            usleep(100000);
            if(symbol == 'q')
                break;
        }

    }while(symbol != 'q');
}

void Window::drawDelivery(int x){
    drawMutex.lock();
    mvwprintw(window, 2, x, "-");
    mvwprintw(window, 2, x - 1, "-");
    mvwprintw(window, 2, x + 1, "-");
    mvwprintw(window, 2, x - 2, "o");
    mvwprintw(window, 2, x + 2, "o");
    drawMutex.unlock();
    wrefresh(window);
}

void Window::eraseDelivery(int x){
    drawMutex.lock();
    mvwprintw(window, 2, x, " ");
    mvwprintw(window, 2, x - 1, " ");
    mvwprintw(window, 2, x + 1, " ");
    mvwprintw(window, 2, x - 2, " ");
    mvwprintw(window, 2, x + 2, " ");
    drawMutex.unlock();
    wrefresh(window);
}

void Window::supplyDelivery(){
    vegetableMutex.lock();
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(vegetablesVec[i].size() < 55){
                Vegetable vegetable(i);
                vegetablesVec[i].push_back(vegetable);
            }
        }
    }
    vegetableMutex.unlock();
}

void Window::useCustomerWithThreads(int threadId){
    while(threadsOnCheck[threadId]){
        
        if(symbol == 'q'){
            break;
        }

        if(customersVect[threadId]->getPositionX() >= 3){
            if(customersVect[threadId]->getPositionX() == 40){
                if(canDoShopping(threadId)){
                    customerVectMutex.lock();
                    doShopping(threadId);
                    customerVectMutex.unlock();
                    drawShelfs();
                    baseDraw();
                    std::this_thread::sleep_for (std::chrono::milliseconds(customersVect[threadId]->getShoppingTime()));
                    customerVectMutex.lock();
                    eraseCustomer(threadId);
                    customersVect[threadId]->setPositionX(customersVect[threadId]->getPositionX() - 1);
                    drawCustomer(threadId);
                    customerVectMutex.unlock();
                }
            }else{
                if(canCustomerMove(threadId)){
                    customerVectMutex.lock();
                    eraseCustomer(threadId);
                    customersVect[threadId]->setPositionX(customersVect[threadId]->getPositionX() - 1);
                    drawCustomer(threadId);
                    customerVectMutex.unlock();
                }
                else{
                    std::this_thread::sleep_for (std::chrono::milliseconds(100));
                }
            }
            std::this_thread::sleep_for (std::chrono::milliseconds(customersVect[threadId]->getWalkSpeed()));
                
            }else{
            customerVectMutex.lock();
            eraseCustomer(threadId);
            customersVect[threadId]->setPositionX(0);
            customerVectMutex.unlock();
            threadsOnCheck[threadId] = false;
            }  
    }
}

bool Window::canDoShopping(int customerId){
    vegetableMutex.lock();
    if(vegetablesVec[0].size() < customersVect[customerId]->getShoppingList().getVege0()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[1].size() < customersVect[customerId]->getShoppingList().getVege1()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[2].size() < customersVect[customerId]->getShoppingList().getVege2()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[3].size() < customersVect[customerId]->getShoppingList().getVege3()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[4].size() < customersVect[customerId]->getShoppingList().getVege4()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[5].size() < customersVect[customerId]->getShoppingList().getVege5()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[6].size() < customersVect[customerId]->getShoppingList().getVege6()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[7].size() < customersVect[customerId]->getShoppingList().getVege7()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[8].size() < customersVect[customerId]->getShoppingList().getVege8()){
        vegetableMutex.unlock();
        return false;
    }
    if(vegetablesVec[9].size() < customersVect[customerId]->getShoppingList().getVege9()){
        vegetableMutex.unlock();
        return false;
    }

    vegetableMutex.unlock();
    return true;
}

void Window::doShopping(int customerId){
    vegetableMutex.lock();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege0(); i++)
        vegetablesVec[0].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege1(); i++)
        vegetablesVec[1].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege2(); i++)
        vegetablesVec[2].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege3(); i++)
        vegetablesVec[3].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege4(); i++)
        vegetablesVec[4].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege5(); i++)
        vegetablesVec[5].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege6(); i++)
        vegetablesVec[6].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege7(); i++)
        vegetablesVec[7].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege8(); i++)
        vegetablesVec[8].pop_back();
    for(int i = 0; i < customersVect[customerId]->getShoppingList().getVege9(); i++)
        vegetablesVec[9].pop_back();
    vegetableMutex.unlock();
}

bool Window::canCustomerMove(int customerId){
    if(customerId > 0){
        if(!(customersVect[customerId - 1]->getPositionX() <= 3)){
            if(customersVect[customerId]->getPositionX() >= customersVect[customerId - 1]->getPositionX() + 4){
                return true;
            }else{
                return false;
            }
        }else{
            return true;
        }
    }else{
        return true;
    }
}