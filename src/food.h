#include "object.h"

class Food: public Object{
    public:
        Food(int x, int y);
        Food(const Food &source);
        Food(Food &&source);
        Food &operator=(Food &source);
        Food &operator=(Food &&source);
        ~Food();
        void updateSpeed(float &speed);
        void updateScore(int &score);
        void updateSnakeBody(Snake &snake);
};