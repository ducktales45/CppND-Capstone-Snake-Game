#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "paddle.h"
#include "ball.h"

class Renderer 
{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Paddle paddle1, Paddle paddle2, Ball ball);
  void UpdateWindowTitle(int score1, int score2, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif