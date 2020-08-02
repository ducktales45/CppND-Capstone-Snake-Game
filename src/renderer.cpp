#include "renderer.h"
#include <iostream>
#include <string>
#include "ball.h"
#include "paddle.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) 
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) 
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) 
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) 
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() 
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, Paddle  paddle1, Paddle paddle2, Ball ball)
{
  //SDL_Rect block;
  //block.w = screen_width / grid_width;
  //block.h = screen_height / grid_height;
  
  
  //SDL_Rect paddle;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // // Render food
  // SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  // block.x = food.x * block.w;
  // block.y = food.y * block.h;
  // SDL_RenderFillRect(sdl_renderer, &block);

  // // Render snake's body
  // SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  // for (SDL_Point const &point : snake.body) {
  //   block.x = point.x * block.w;
  //   block.y = point.y * block.h;
  //   SDL_RenderFillRect(sdl_renderer, &block);
  //}

  // // Render snake's head
  // block.x = static_cast<int>(snake.head_x) * block.w;
  // block.y = static_cast<int>(snake.head_y) * block.h;
  // if (snake.alive) 
  // {
  //   SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  // } 
  // else 
  // {
  //   SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  // }
  // SDL_RenderFillRect(sdl_renderer, &block);

// Render Net
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF); 

  for (int i = 0; i < screen_height; i+=5)
  {
      SDL_RenderDrawPoint(sdl_renderer, screen_width / 2 , i);        
  }

  // Render Ball
  // create ball
 // Ball ball((screen_width / 2.0) - (BALL_WIDTH / 2.0), (screen_height / 2.0) - (BALL_HEIGHT / 2.0));
  
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  // draw ball
  ball.Draw(sdl_renderer);
  // draw paddle 1
  //SDL_Rect paddle1Rect;
  //Vector2D paddle1Loc = paddle1.GetLocation();

  // paddle1Rect.x = paddle1Loc.x;
  // paddle1Rect.y = paddle1Loc.y;
  // paddle1Rect.w = PADDLE_WIDTH;
  // paddle1Rect.h = PADDLE_HEIGHT;
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  paddle1.Draw(sdl_renderer);
  //SDL_RenderFillRect(sdl_renderer, &paddle1Rect);

  // draw paddle 2
  //SDL_Rect paddle2Rect;
  //Vector2D paddle2Loc(screen_width - 50.0f, (screen_height / 2.0f) - (PADDLE_HEIGHT / 2.0f));
  
  paddle2.Draw(sdl_renderer);
  //SDL_RenderFillRect(sdl_renderer, &paddle2Rect);
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
