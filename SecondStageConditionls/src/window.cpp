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
    symbol = 'p';
}

Window::~Window(){

    endwin();       //kończę korzystanie z ncurses
}

void Window::startWindow(){

    srand(time(NULL));

    std::vector<std::thread> threadVect;
    /*for(int i = 0; i < 6; i++)
        balls.push_back(new Ball( 2, width/2, 1));

    balls.push_back(new Ball( 2, width/2, 3));
    balls.push_back(new Ball( 2, width/2, 7));
    */
    for(int i = 0; i < balls.size() + 1; i++){
        balls.push_back(new Ball( 2, width/2, getRandomDirection()));
        symbol = getch();
        if(symbol == 'q')
        {
            condition.notify_all();
            break;
        }
        threadsOnCheck.push_back(true);
        threadVect.push_back(std::thread([&](){useBallWithThreads(i);}));
        sleep(1);
        for(int j = 0; j < threadsOnCheck.size(); j++){
            if(!threadsOnCheck[j])
                if(threadVect[j].joinable())
                    threadVect[j].join();
        }
    }
    
    for(auto& t : threadVect){
        if(t.joinable())
            t.join();
    }
    
}

void Window::useBallWithThreads(int threadId){
    while(threadsOnCheck[threadId]){

        if(symbol == 'q'){
            break;
        }

        //fieldsCounter();

        if(balls[threadId]->getSpeed() < 1000){
    
            //ballsVectLock.lock();
            std::unique_lock<std::mutex> locker(ballsVectLock);
            //if(canBallMove(threadId)){
                setBall(threadId);
                displayBall(threadId);
            //}
            //else{
                //condition.wait(ballsVectLock); 
            //    condition.wait(locker, [&](){ return canBallMove(threadId); }); 
                //[&](){useBallWithThreads(i);})
                
            //}
            locker.unlock();
            //ballsVectLock.unlock();
            std::this_thread::sleep_for (std::chrono::milliseconds(balls[threadId]->getSpeed()));
        }
        else{
            ballsVectLock.lock();
            eraseBall(threadId);
            ballsVectLock.unlock();
            threadsOnCheck[threadId] = false;
        }  
    }
}

void Window::setBall(int i){
   
    if(balls[i]->getCurrentX() <= 1 || balls[i]->getCurrentX() >= (this->width - 2))
    {
        updateDirection(i, 0);  // "0" - symbolizuje sciany pionowe
        balls[i]->setSpeed(balls[i]->getSpeed()*2);
    }
    if(balls[i]->getCurrentY() <= 1 || balls[i]->getCurrentY() >= ( height - 2 ))
    {
        updateDirection(i, 1);    // "1" - sumbolizuje sciany poziome
        balls[i]->setSpeed(balls[i]->getSpeed()*2);           
    }

    moveBall(i);     
}

void Window::updateDirection(int i, int wall){
    switch(balls[i]->getDirection())
    {
        // [0][1][2]
        // [7] o [3]
        // [6][5][4]
        // wall = 0 - sciana pionowa
        // wall = 1 - sciana pozioma

        case 0:
            if(wall == 0){
                balls[i]->setDirection(2);
            }
            else if(wall == 1){
                balls[i]->setDirection(6);
            }
            break;
        case 1:
            balls[i]->setDirection(5);
            break;
        case 2:
            if(wall == 0){
                balls[i]->setDirection(0);
            }
            else if(wall == 1){
                balls[i]->setDirection(4);
            }
            break;
        case 3:
            balls[i]->setDirection(7);
            break;
        case 4:
            if(wall == 0){
                balls[i]->setDirection(6);
            }
            else if(wall == 1){
                balls[i]->setDirection(2);
            }
            break;
        case 5:
            balls[i]->setDirection(1);
            break;
        case 6:
            if(wall == 0){
                balls[i]->setDirection(4);
            }
            else if(wall == 1){
                balls[i]->setDirection(0);
            }
            break;
        case 7:
            balls[i]->setDirection(3);
            break;
        default:
            break;
    }
}

void Window::moveBall(int i){
    switch(balls[i]->getDirection())
    {

        // [0][1][2]
        // [7] o [3]
        // [6][5][4]

        case 0:
            balls[i]->setCurrentX(balls[i]->getCurrentX() - 1);
            balls[i]->setCurrentY(balls[i]->getCurrentY() + 1);
            break;
        case 1:
            balls[i]->setCurrentY(balls[i]->getCurrentY() + 1);
            break;
        case 2:
            balls[i]->setCurrentX(balls[i]->getCurrentX() + 1);
            balls[i]->setCurrentY(balls[i]->getCurrentY() + 1);
            break;
        case 3:
            balls[i]->setCurrentX(balls[i]->getCurrentX() + 1);
            break;              
        case 4:
            balls[i]->setCurrentX(balls[i]->getCurrentX() + 1);
            balls[i]->setCurrentY(balls[i]->getCurrentY() - 1);
            break;
        case 5:
            balls[i]->setCurrentY(balls[i]->getCurrentY() - 1);
            break;
        case 6:
            balls[i]->setCurrentX(balls[i]->getCurrentX() - 1);
            balls[i]->setCurrentY(balls[i]->getCurrentY() - 1);
            break;
        case 7:
            balls[i]->setCurrentX(balls[i]->getCurrentX() - 1);
            break;
        default:
            break;
    }
}

void Window::displayBall(int i){
   
    mvwprintw(window, balls[i]->getLastY(), balls[i]->getLastX(), " ");
    mvwprintw(window, balls[i]->getCurrentY(), balls[i]->getCurrentX(), "o");
    wrefresh(window);
    balls[i]->setLastX(balls[i]->getCurrentX());     
    balls[i]->setLastY(balls[i]->getCurrentY());    
    
}

void Window::eraseBall(int i){
    mvwprintw(window, balls[i]->getLastY(), balls[i]->getLastX(), " ");
    wrefresh(window);
}

int Window::getRandomDirection(){
 
   int direction;
   do{
       direction = rand()% 8;
   }while(direction == 1);
   return direction;
}

 /*
void Window::fieldsCounter(){
    fLeft = 0;
    fRight = 0;
    fCenter = 0;
    for(int i = 0; i < balls.size(); i++){
        if(balls[i]->getCurrentX() < ((width + 1)/3))
            fLeft++;
        else if(balls[i]->getCurrentX() >= ((width + 1)/3) && balls[i]->getCurrentX() < ((width*2 + 1)/3))
            fCenter++;
        else
            fRight++;
    }


   
    //mvwprintw(window, 0, 1, "L%i", fLeft);
    //mvwprintw(window, 0, 4, "C%i", fCenter);
    //mvwprintw(window, 0, 7, "P%i", fRight);
    //wrefresh(window);
   
} 

bool Window::canBallMove(int ballId){
    //1 - lewa
    //2 - środek
    //3 - prawa
    if(isOnTheBorder(ballId)){
        if(canBallSwitchFields(balls[ballId]->getCurrentX(), ballField(ballId)))   {
            return true;
            condition.notify_one();
        }     
        return false;
    }
    else
        return true;
        
}

int Window::ballField(int ballId){
    if(balls[ballId]->getCurrentX() < (width/3))
        return 1;   //lewa
    else if(balls[ballId]->getCurrentX() >= (width/3) && balls[ballId]->getCurrentX() <= (width*2/3))
        return 2;   //środek
    else
        return 3;   //prawa
}

bool Window::isOnTheBorder(int ballId){
    if(balls[ballId]->getCurrentX() == (width/3) || balls[ballId]->getCurrentX() == (width*2/3))
        return true;
    return false;
}

bool Window::canBallSwitchFields(int direction, int field){
    switch(field){
        case 1: //lewy
            if((fLeft + 1) >= fCenter)
                return true;
            return false;
            break;
        case 2: //środek
            if(direction == 0 || direction == 6 || direction == 7){     //idzie w lewo
                if((fCenter + 1) >= fLeft)
                    return true;
                return false;
            }
            else{       //idzie w prawo
                if((fCenter + 1) >= fRight)
                    return true;
                return false;
            }
            break;
        case 3: //prawy
            if((fRight + 1) >= fCenter)
                return true;
            return false;
            break;
        default:
            return false;
            break;
    }
}
*/