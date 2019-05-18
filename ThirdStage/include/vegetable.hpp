#pragma once

class Vegetable{
    private:
    int vegetableType;

    public:
    Vegetable(int value);
    ~Vegetable();
    int getVegetableType();
    void setVegetableType(int value);
};