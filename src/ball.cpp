#include "ball.h"

Ball::Ball(Vector2D location): location(location)
{   
    rect.x = static_cast<int>(location.x);
    rect.y = static_cast<int>(location.y);
    rect.w = BALL_WIDTH;
    rect.y = BALL_HEIGHT;
}

void Ball::Draw(SDL_Renderer* renderer)
{
    rect.x = static_cast<int>(location.x);
    rect.y = static_cast<int>(location.y);

    SDL_RenderFillRect(renderer, &rect);
}