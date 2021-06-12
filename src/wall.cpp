#include "wall.h"

Wall::Wall(int x, int y){
    color = {0xCC, 0x00, 0xFF, 0xFF};
    coords.x = x;
    coords.y = y;
}
Wall::Wall(const Wall &source){
    color = source.color;
    coords = source.coords;
}
Wall::Wall(Wall &&source){
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
}
Wall& Wall::operator=(Wall &source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    return *this;
}
Wall& Wall::operator=(Wall &&source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
    return *this;
}
Wall::~Wall(){};
void Wall::updateSpeed(float &speed){
    speed = 0.1f;
}
void Wall::updateScore(int &score){
    score=0;
}
void Wall::updateSnakeBody(Snake &snake){
    snake.Kill();
}