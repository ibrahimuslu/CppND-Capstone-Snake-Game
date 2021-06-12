#include "trap.h"

Trap::Trap(int x, int y){
    color = {0xFF, 0x00, 0xCC, 0xFF};
    coords.x = x;
    coords.y = y;
}
Trap::Trap(const Trap &source){
    color = source.color;
    coords = source.coords;
}
Trap::Trap(Trap &&source){
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
}
Trap& Trap::operator=(Trap &source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    return *this;
}
Trap& Trap::operator=(Trap &&source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
    return *this;
}
Trap::~Trap(){};
void Trap::updateSpeed(float &speed){
    speed -= 0.02f;
}
void Trap::updateScore(int &score){
    score--;
}
void Trap::updateSnakeBody(Snake &snake){
    snake.ShrinkBody();
}