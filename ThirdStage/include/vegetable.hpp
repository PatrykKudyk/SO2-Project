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

    /*
    enum vegetables
    {
        carrot = 0,     //marchew
        onion = 1,      //cebula
        lettuce = 2,    //sałata
        cucumber = 3,   //ogórek
        pepper = 4,     //papryka
        corn = 5,       //kukurydza
        bean = 6,       //fasola
        courgette = 7,  //cukinia
        mushrooms = 8,  //grzyby
        tomatoe = 9    //pomidor
    };
    */