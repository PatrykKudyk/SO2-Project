#pragma once 

class ShoppingList{
    private:
    short unsigned int vege0;
    short unsigned int vege1;
    short unsigned int vege2;
    short unsigned int vege3;
    short unsigned int vege4;
    short unsigned int vege5;
    short unsigned int vege6;
    short unsigned int vege7;
    short unsigned int vege8;
    short unsigned int vege9;

    public:
    ShoppingList();
    ~ShoppingList();
    unsigned short int getVege0();
    unsigned short int getVege1();
    unsigned short int getVege2();
    unsigned short int getVege3();
    unsigned short int getVege4();
    unsigned short int getVege5();
    unsigned short int getVege6();
    unsigned short int getVege7();
    unsigned short int getVege8();
    unsigned short int getVege9();
    void setVege0(unsigned short int value);
    void setVege1(unsigned short int value);
    void setVege2(unsigned short int value);
    void setVege3(unsigned short int value);
    void setVege4(unsigned short int value);
    void setVege5(unsigned short int value);
    void setVege6(unsigned short int value);
    void setVege7(unsigned short int value);
    void setVege8(unsigned short int value);
    void setVege9(unsigned short int value);
};