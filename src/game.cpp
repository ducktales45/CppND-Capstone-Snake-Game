#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game( std::size_t grid_width, std::size_t grid_height): snake(grid_width, grid_height),
            paddle1(50.0f, (grid_height  / 2.0f) - (PADDLE_HEIGHT / 2.0f), 1.5f),
            paddle2(grid_width - 50.0f, (grid_height / 2.0f) - (PADDLE_HEIGHT / 2.0f), 1.5f),
            ball((grid_width / 2.0) - (BALL_WIDTH / 2.0), (grid_height / 2.0) - (BALL_HEIGHT / 2.0), -1.0f, 1.0f)
{}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) 
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paddle1, paddle2);
    Update();
    renderer.Render(snake, paddle1, paddle2, ball);
    
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

bool Game::FIsCollision(Paddle& paddle)
{
  float ballLeft = ball.GetXCoord();
  float ballRight = ball.GetXCoord() + BALL_WIDTH;
  float ballTop = ball.GetYCoord();
  float ballBottom = ball.GetYCoord() + BALL_HEIGHT;

  float paddleLeft = paddle.GetXCoord();
	float paddleRight = paddle.GetXCoord() + PADDLE_WIDTH;
	float paddleTop = paddle.GetYCoord();
	float paddleBottom = paddle.GetYCoord() + PADDLE_HEIGHT;

  if (ballLeft >= paddleRight)
	{
		return false;
	}

	if (ballRight <= paddleLeft)
	{
		return false;
	}

	if (ballTop >= paddleBottom)
	{
		return false;
	}

	if (ballBottom <= paddleTop)
	{
		return false;
	}

	return true;
}

void Game::Update() 
{  
  paddle1.Update();
  paddle2.Update();
  ball.Update();
  if (FIsCollision(paddle1) || FIsCollision(paddle2))
  {
    ball.ChangeXDir();
    ball.ChangeYDir();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }