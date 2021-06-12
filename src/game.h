#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include "wall.h"
#include "trap.h"

class Controller;
class Game {
 public:  
  enum class State {gRunning=0, gEnd, gPaused, sDied};
  Game(std::size_t grid_width, std::size_t grid_height, std::string level);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  int GetDuration() const;
  int GetStatus() const;
  void SetStatus(State status);
 private:
  std::string title[4] = {"Running","","Paused!","Snake died, Game Over!"};
  Snake snake;
  std::vector<std::unique_ptr<Object>> objects;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int status{0};
  int score{0};
  int duration{0};
  void ReplaceObject(int item);
  void Update();
};

#endif