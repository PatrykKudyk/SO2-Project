#include <ncurses.h>
#include <vector>
#include "ball.hpp"

class Window{
    private:
    WINDOW *window;         //okno
    std::vector<Ball *> balls;    //vektor kulek

    public:
    Window();
    ~Window();
    void startWindow();
    void displayBalls();
};