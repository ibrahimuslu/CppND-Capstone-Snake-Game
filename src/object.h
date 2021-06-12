#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "SDL.h"
#include "snake.h"

struct Color {
    int red;
    int blue;
    int green;
    int alpha;
};
class Object {
    public:
        virtual ~Object(){}
        virtual void updateSpeed(float &speed)= 0;
        virtual void updateScore(int &score)= 0;
        virtual void updateSnakeBody(Snake &snake)= 0;
        Color color;
        SDL_Point coords;
};
#endif