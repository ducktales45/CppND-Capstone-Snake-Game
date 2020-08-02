#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "paddle.h"

void Controller::ChangeDirection(Paddle &paddle, Paddle::Direction input) const 
{   
  paddle.direction = input;  
}

void Controller::HandleInput(bool &running, Paddle &paddle1, Paddle &paddle2) const 
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) 
  {
    if (e.type == SDL_QUIT) 
    {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) 
    {
      switch (e.key.keysym.sym) 
      {
        case SDLK_UP:
          std::cout << "up is pressed" << "\n";
          ChangeDirection(paddle1, Paddle::Direction::kUp);
          break;

        case SDLK_DOWN:
          std::cout << "down is pressed" << "\n";
          ChangeDirection(paddle1, Paddle::Direction::kDown);
          break;

        case SDLK_w:
          std::cout << "w is pressed" << "\n";
          ChangeDirection(paddle2, Paddle::Direction::kUp);
          break;
        
        case SDLK_s:
          std::cout << "s is pressed" << "\n";
          ChangeDirection(paddle2, Paddle::Direction::kDown);
          break;    
      }
    }
    else if (e.type == SDL_KEYUP)
      ChangeDirection(paddle1, Paddle::Direction::kNone);
      ChangeDirection(paddle2, Paddle::Direction::kNone);
  }
}