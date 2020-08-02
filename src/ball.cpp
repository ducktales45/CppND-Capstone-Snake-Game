#include "ball.h"

Ball::Ball(float x, float y, float vel_x, float vel_y): x(x), y(y), vel_x(vel_x), vel_y(vel_y)
{   
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
    rect.w = BALL_WIDTH;
    rect.h = BALL_HEIGHT;
}

void Ball::Update()
{
   x += vel_x;
   y += vel_y;

}

void Ball::Draw(SDL_Renderer* renderer)
{
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);

    SDL_RenderFillRect(renderer, &rect);
}