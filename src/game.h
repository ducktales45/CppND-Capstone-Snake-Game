#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "paddle.h"
#include "ball.h"

class Game 
{
 public:
  Game(std::size_t screen_width, std::size_t screen_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
 // int GetScore() const;
  bool FIsCollision(Paddle& paddle);
  void PrintFinalScore() const;
  const std::size_t screen_width;
  const std::size_t screen_height;
 private:
  Paddle paddle1;
  Paddle paddle2;
  Ball ball;
  int score1{0};
  int score2{0};
  void Update();
};

#endif