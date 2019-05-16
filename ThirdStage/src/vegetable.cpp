#include "../include/vegetable.hpp"

Vegetable::Vegetable(int value){
    vegetableType = value;
}

Vegetable::~Vegetable(){

}

int Vegetable::getVegetableType(){
    return vegetableType;
}

void Vegetable::setVegetableType(int value){
    vegetableType = value;
}