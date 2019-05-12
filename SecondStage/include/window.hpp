#pragma once
#include <ncurses.h>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <condition_variable>

#include "ball.hpp"

class Window{
    private:
    WINDOW *window;         //okno
    int width;
    int height;
    int fLeft;
    int fRight;
    int fCenter;
    std::vector<Ball *> balls;    //vektor kulek
    std::vector<bool> threadsOnCheck;
    std::mutex ballsVectLock;
    std::condition_variable leftToCenter;
    std::condition_variable rightToCenter;
    std::condition_variable centerToLeft;
    std::condition_variable centerToRight;
    

    char symbol;
    

    public:
    Window(int height, int width);
    ~Window();
    void startWindow();
    void useBallWithThreads(int threadId);
    void setBall(int i);
    void updateDirection(int i, int wall);
    void moveBall(int i);
    void displayBall(int i);
    void eraseBall(int i);
    int getRandomDirection();
    void fieldsCounter();
    bool canBallMove(int ballId);
    int ballField(int ballId, int direction);
    bool isOnTheBorder(int ballId);
    bool canBallSwitchFields(int direction, int field);
    int whichCondition(int direction, int x);
    void notifies();
};