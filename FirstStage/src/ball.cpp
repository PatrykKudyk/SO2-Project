#include "../include/ball.hpp"

Ball::Ball(int y, int x, int direction){
    this->currentX = x;
    this->currentY = y;
    this->direction = direction;
}

Ball::~Ball(){

}

int Ball::getCurrentX(){
    return this->currentX;
}

int Ball::getCurrentY(){
    return this->currentY;
}

int Ball::getLastX(){
    return this->lastX;
}

int Ball::getLastY(){
    return this->lastY;
}

int Ball::getDirection(){
    return this->direction;
}

void Ball::setCurrentX(int val){
    this->currentX = val;
}

void Ball::setCurrentY(int val){
    this->currentY = val;
}

void Ball::setLastX(int val){
    this->lastX = val;
}

void Ball::setLastY(int val){
    this->lastY = val;
}

void Ball::setDirection(int val){
    this->direction = val;
}