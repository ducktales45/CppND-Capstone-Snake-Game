#include "paddle.h"

Paddle::Paddle(float x, float y, float vel_y): x(x), y(y), vel_y(vel_y)
{   
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;
}

void Paddle::Update()
{

    switch (direction) 
    {
        case Direction::kUp:
            y -= vel_y;
            break;

        case Direction::kDown:
            y += vel_y;
            break;  
        default:
              y += 0;
              break;    

    }
    if (y < 0)
    {
        // restrict upper range of y to top of screen
        y = 0;
    }
    else if (y > WINDOW_HEIGHT - PADDLE_HEIGHT)
    {
        // restrict range of y to bottom of screen
        y = WINDOW_HEIGHT - PADDLE_HEIGHT;
    }
}

void Paddle::Draw(SDL_Renderer* renderer)
{   
    rect.y = static_cast<int>(y);

    SDL_RenderFillRect(renderer, &rect);
}

