#pragma once
#include <ncurses.h>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "ball.hpp"

class Window{
    private:
    WINDOW *window;         //okno
    int width;
    int height;
    std::vector<Ball *> balls;    //vektor kulek
    std::vector<bool> threadsOnCheck;
    std::vector<std::thread> threadVect;
    std::mutex ballsVectLock;
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
};