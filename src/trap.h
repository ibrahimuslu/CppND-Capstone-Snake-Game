#include "object.h"
 
class Trap: public Object{
    public:
        Trap(int x, int y);
        Trap(const Trap &source);
        Trap(Trap &&source);
        Trap &operator=(Trap &source);
        Trap &operator=(Trap &&source);
        ~Trap();
        void updateSpeed(float &speed);
        void updateScore(int &score);
        void updateSnakeBody(Snake &snake);
};