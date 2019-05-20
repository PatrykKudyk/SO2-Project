#pragma once
#include <ncurses.h>
#include <vector>
#include "../include/vegetable.hpp"
#include "../include/customer.hpp"
#include <mutex>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <condition_variable>


class Window{
    private:
    WINDOW *window;
    int width;
    int height;
    char symbol;
    std::vector<std::vector<Vegetable>> vegetablesVec;
    std::vector<bool> threadsOnCheck;
    std::vector<Customer *> customersVect;
    std::mutex customerVectMutex;
    std::mutex drawMutex;
    std::mutex vegetableMutex;
    std::condition_variable queueCondition;

    public:
    Window(int height, int width);
    ~Window();
    void createVegetableVectors();
    void startWindow();
    void baseDraw();
    void drawCustomer(int customerId);
    void eraseCustomer(int customerId);
    void drawShelfs();
    void drawVegetables(int startingPointX, std::vector<Vegetable> vegetables);
    void drawSomeVegetables(int startX, int startY, char vegetable, int vegeNumber);
    void drawRow(int startX, int startY, char vegetableChar, int vegeNumber);
    void clearVegetables(int startingPointX);
    void deliveryThread();
    void drawDelivery(int x);
    void eraseDelivery(int x);
    void supplyDelivery();
    void useCustomerWithThreads(int threadId);
    bool canDoShopping(int customerId);
    void doShopping(int customerId);
    bool canCustomerMove(int customerId);
};