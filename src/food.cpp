#include "food.h"

Food::Food(int x, int y){
    color = {0xFF, 0xCC, 0x00, 0xFF};
    coords.x = x;
    coords.y = y;
}
Food::Food(const Food &source){
    color = source.color;
    coords = source.coords;
}
Food::Food(Food &&source){
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
}
Food& Food::operator=(Food &source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    return *this;
}
Food& Food::operator=(Food &&source){
    if (this == &source)
            return *this;
    color = source.color;
    coords = source.coords;
    source.color = {};
    source.coords = {};
    return *this;
}
Food::~Food(){};
void Food::updateSpeed(float &speed){
    speed += 0.02f;
}
void Food::updateScore(int &score){
    score++;
}
void Food::updateSnakeBody(Snake &snake){
    snake.GrowBody();
}