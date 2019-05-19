#include "../include/customer.hpp"

Customer::Customer(int x){
    positionX = x;
}

Customer::~Customer(){

}

ShoppingList Customer::getShoppingList(){
    return shoppingList;
}

int Customer::getPositionX(){
    return positionX;
}

void Customer::setPositionX(int value){
    positionX = value;
}