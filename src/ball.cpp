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

void Ball::ResetBall(const std::size_t screen_width, const std::size_t screen_height)
{
    x = (screen_width / 2.0) - (BALL_WIDTH / 2.0);
    y = (screen_height / 2.0) - (BALL_HEIGHT / 2.0);
    vel_x = -1.0 * vel_x;
}
void Ball::Draw(SDL_Renderer* renderer)
{
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);

    SDL_RenderFillRect(renderer, &rect);
}