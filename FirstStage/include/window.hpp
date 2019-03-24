#include <ncurses.h>
#include <vector>
#include "ball.hpp"
#include <mutex>

class Window{
    private:
    WINDOW *window;         //okno
    int width;
    int height;
    std::vector<Ball *> balls;    //vektor kulek
    std::mutex ballsVectLock;

    public:
    Window(int height, int width);
    ~Window();
    void startWindow();
    void setBall(int i);
    void updateDirection(int i, int wall);
    void moveBall(int i);
    void displayBall(int i);
};