#pragma once

class Ball{
    private:
    int currentX;
    int currentY;
    int lastX;
    int lastY;
    int direction;
    int speed;

    public:
    Ball(int y, int x, int direction);
    ~Ball();
    int getCurrentX();
    int getCurrentY();
    int getLastX();
    int getLastY();
    int getDirection();
    int getSpeed();
    void setCurrentX(int val);
    void setCurrentY(int val);
    void setLastX(int val);
    void setLastY(int val);
    void setDirection(int val);
    void setSpeed(int val);
};