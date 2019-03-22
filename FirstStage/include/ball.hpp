

class Ball{
    private:
    int currentX;
    int currentY;
    int lastX;
    int lastY;
    int direction;

    public:
    Ball(int y, int x, int direction);
    ~Ball();
    int getCurrentX();
    int getCurrentY();
    int getLastX();
    int getLastY();
    int getDirection();
    void setCurrentX(int val);
    void setCurrentY(int val);
    void setLastX(int val);
    void setLastY(int val);
    void setDirection(int val);
};