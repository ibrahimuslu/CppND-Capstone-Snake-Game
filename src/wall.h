#include "object.h"

class Wall: public Object{
    public:
        Wall(int x, int y);
        Wall(const Wall &source);
        Wall(Wall &&source);
        Wall &operator=(Wall &source);
        Wall &operator=(Wall &&source);
        ~Wall();
        void updateSpeed(float &speed);
        void updateScore(int &score);
        void updateSnakeBody(Snake &snake);
};