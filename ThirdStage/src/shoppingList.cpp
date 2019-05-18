#include "../include/shoppingList.hpp"
#include <ctime>
#include <cstdlib>

ShoppingList::ShoppingList(){
    vege0 = rand() % 5;
    vege1 = rand() % 5;
    vege2 = rand() % 5;
    vege3 = rand() % 5;
    vege4 = rand() % 5;
    vege5 = rand() % 5;
    vege6 = rand() % 5;
    vege7 = rand() % 5;
    vege8 = rand() % 5;
    vege9 = rand() % 5;
}

ShoppingList::~ShoppingList(){

}

unsigned short int ShoppingList::getVege0(){
    return vege0;
}

unsigned short int ShoppingList::getVege1(){
    return vege1;
}

unsigned short int ShoppingList::getVege2(){
    return vege2;
}

unsigned short int ShoppingList::getVege3(){
    return vege3;
}

unsigned short int ShoppingList::getVege4(){
    return vege4;
}

unsigned short int ShoppingList::getVege5(){
    return vege5;
}

unsigned short int ShoppingList::getVege6(){
    return vege6;
}

unsigned short int ShoppingList::getVege7(){
    return vege7;
}

unsigned short int ShoppingList::getVege8(){
    return vege8;
}

unsigned short int ShoppingList::getVege9(){
    return vege9;
}

void ShoppingList::setVege0(unsigned short int value){
    vege0 = value;
}

void ShoppingList::setVege1(unsigned short int value){
    vege1 = value;
}

void ShoppingList::setVege2(unsigned short int value){
    vege2 = value;
}

void ShoppingList::setVege3(unsigned short int value){
    vege3 = value;
}

void ShoppingList::setVege4(unsigned short int value){
    vege4 = value;
}

void ShoppingList::setVege5(unsigned short int value){
    vege5 = value;
}

void ShoppingList::setVege6(unsigned short int value){
    vege6 = value;
}

void ShoppingList::setVege7(unsigned short int value){
    vege7 = value;
}

void ShoppingList::setVege8(unsigned short int value){
    vege8 = value;
}

void ShoppingList::setVege9(unsigned short int value){
    vege9 = value;
}