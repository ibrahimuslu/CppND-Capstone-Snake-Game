#include "game.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height, std::string level)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  // default game counts
  int fc=1,tc=1,wc=1; // food count
  if (level== "easy")
  {
    fc=8;
    tc=1;
    wc=1;
  }else if(level== "hard")
  {  
    fc=1;
    tc=8;
    wc=4;
  }
  for(int i = 0;i < fc; i++)
    objects.emplace_back(std::make_unique<Food>(Food(random_w(engine),random_h(engine))));
  for(int j = 0;j < tc; j++)
    objects.emplace_back(std::make_unique<Trap>(Trap(random_w(engine),random_h(engine))));
  for(int k = 0;k < wc; k++)
    objects.emplace_back(std::make_unique<Wall>(Wall(random_w(engine),random_h(engine))));

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  int fps = 0;

  while (GetStatus()!= 1) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    
    controller.HandleInput(status, snake);
    Update();
    renderer.Render(snake, objects);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
    
    renderer.UpdateWindowTitle(score, fps, title[(int)status]);
    
    // Calculate FPS
    if (frame_end - title_timestamp >= 1000) {
      fps = frame_count;
      frame_count = 0;
      title_timestamp = frame_end;
    }
    
    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    duration = frame_end;
  }
}

void Game::ReplaceObject(int item) {
  int x, y;
  
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item or a trap before placing
    // food.
    int empty_place = 0;
    if (snake.SnakeCell(x, y)) {
      empty_place++;
    }

    for(auto &o: objects){
      if(o->coords.x == x && o->coords.y == y){
        empty_place++;
      }
    }
    if(empty_place == 0){
      objects[item]->coords.x = x;
      objects[item]->coords.y = y;
      return;
    } else {
      empty_place = 0;
    }
    
  }
}

void Game::Update() {
  if (GetStatus() != 0) return;

  snake.Update();
  if(!snake.IsAlive()) {
    SetStatus(State::sDied); 
    return; 
  }
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's objects over here
  int i=0; // vector erase count
  for(auto &o: objects){
    if (o->coords.x == new_x && o->coords.y == new_y) {
      o->updateScore(score);
      o->updateSnakeBody(snake);
      o->updateSpeed(snake.speed);
      ReplaceObject(i);
      return;
    }
    i++;
  }
}

int Game::GetScore() const { return score; }
int Game::GetDuration() const {return duration/1000; }
int Game::GetSize() const { return snake.size; }
int Game::GetStatus() const { return status; }
void Game::SetStatus(State _status){ status = (int)_status; }