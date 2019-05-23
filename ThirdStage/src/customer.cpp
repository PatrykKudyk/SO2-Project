#include "../include/customer.hpp"

Customer::Customer(int x){
    srand(time(NULL));
    shoppingTime = rand()%400 + 2400;
    walkSpeed = rand()%100 + 100;
    positionX = x;
    color = rand()%4 + 1;
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

short int Customer::getColor(){
    return color;
}

void Customer::setPositionX(int value){
    positionX = value;
}