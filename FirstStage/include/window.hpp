#include <ncurses.h>
#include <vector>
#include "ball.hpp"

class Window{
    private:
    WINDOW *window;         //okno
    int width;
    int height;
    std::vector<Ball *> balls;    //vektor kulek

    public:
    Window(int height, int width);
    ~Window();
    void startWindow();
    void setBalls();
    void updateDirection(int i, int wall);
    void moveBall(int i);
    void displayBalls();
};