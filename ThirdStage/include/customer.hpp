#pragma once
#include "../include/shoppingList.hpp"

class Customer{
    private:
    ShoppingList shoppingList;
    int positionX;
    
    public:
    Customer();
    ~Customer();
    ShoppingList getShoppingList();
    int getPositionX();
    void setPositionX(int value);
};