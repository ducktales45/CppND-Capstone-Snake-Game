#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "paddle.h"

void Controller::ChangeDirection(Paddle &paddle, Paddle::Direction input) const 
{   
  paddle.direction = input;  
}

void Controller::ChangeDirection(Paddle &paddle1, Paddle &paddle2, Paddle::Direction input) const
{
  paddle1.direction = input;
  paddle2.direction = input;
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
          ChangeDirection(paddle1, Paddle::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(paddle1, Paddle::Direction::kDown);
          break;

        case SDLK_w:          
          ChangeDirection(paddle2, Paddle::Direction::kUp);
          break;
        
        case SDLK_s:          
          ChangeDirection(paddle2, Paddle::Direction::kDown);
          break;    
      }
    }
    else if (e.type == SDL_KEYUP)
      ChangeDirection(paddle1, paddle2, Paddle::Direction::kNone);
  }
}