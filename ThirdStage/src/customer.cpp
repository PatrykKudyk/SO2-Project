#include "../include/customer.hpp"

Customer::Customer(int x){
    srand(time(NULL));
    shoppingTime = rand()%400 + 400;
    walkSpeed = rand()%100 + 100;
    positionX = x;

}

Customer::~Customer(){

}

ShoppingList Customer::getShoppingList(){
    return shoppingList;
}

unsigned int Customer::getShoppingTime(){
    return shoppingTime;
}

unsigned int Customer::getWalkSpeed(){
    return walkSpeed;
}

int Customer::getPositionX(){
    return positionX;
}

void Customer::setPositionX(int value){
    positionX = value;
}