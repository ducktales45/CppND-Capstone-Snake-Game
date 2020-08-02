#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "paddle.h"
#include "ball.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  bool FIsCollision(Paddle& paddle);
 private:
  Paddle paddle1;
  Paddle paddle2;
  Ball ball;
  int score{0};
  void Update();
};

#endif