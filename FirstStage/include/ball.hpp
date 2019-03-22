

class Ball{
    private:
    int posX;
    int posY;
    int color;

    public:
    Ball(int x, int y, int color);
    ~Ball();
    int getPosX();
    int getPosY();
    int getColor();
    void setPosX(int val);
    void setPosY(int val);
    void setColor(int val);
};