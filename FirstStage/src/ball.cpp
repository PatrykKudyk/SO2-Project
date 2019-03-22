#include "../include/ball.hpp"

Ball::Ball(int x, int y, int color){
    this->posX = x;
    this->posY = y;
    this->color = color;
}

Ball::~Ball(){

}

int Ball::getPosX(){
    return this->posX;
}

int Ball::getPosY(){
    return this->posY;
}

int Ball::getColor(){
    return this->color;
}

void Ball::setPosX(int val){
    this->posX = val;
}

void Ball::setPosY(int val){
    this->posY = val;
}

void Ball::setColor(int val){
    this->color = val;
}