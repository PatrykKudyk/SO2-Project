#pragma once
#include "../include/shoppingList.hpp"
#include <ctime>
#include <cstdlib>

class Customer{
    private:
    ShoppingList shoppingList;
    int positionX;
    unsigned int shoppingTime;
    unsigned int walkSpeed;
    short int color;

    public:
    Customer(int x);
    ~Customer();
    ShoppingList getShoppingList();
    unsigned int getShoppingTime();
    unsigned int getWalkSpeed();
    int getPositionX();
    short int getColor();
    void setPositionX(int value);
};