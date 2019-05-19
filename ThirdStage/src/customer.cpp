#include "../include/customer.hpp"

Customer::Customer(){
    
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