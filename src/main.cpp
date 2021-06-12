#include <iostream>
#include <chrono>
#include <fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"


inline std::string getCurrentDateTime(){
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return std::string(buf);
}

int main(int argc, char *argv[]) {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  std::string level{"easy"};
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  if(argv[1]) level = argv[1];
  Game game(kGridWidth, kGridHeight, level);

  std::string now = getCurrentDateTime(); // game started at

  std::ofstream gameLog;
  gameLog.open ("gameLog.txt", std::ios_base::out | std::ios_base::app);
  game.Run(controller, renderer, kMsPerFrame);
  gameLog  << now << "\tScore: " << game.GetScore() << "\tSize: " << game.GetSize() << "\tDuration: " << game.GetDuration() << " secs" << std::endl;
  gameLog.close();

  now = getCurrentDateTime(); // game ended at
  std::cout << now << std::endl;
  std::cout << "Game has terminated successfully!" << std::endl;
  std::cout << "Score: " << game.GetScore() << std::endl;
  std::cout << "Size: " << game.GetSize() << std::endl;
  std::cout << "Duration: " << game.GetDuration() << std::endl;
  

  return 0;
}