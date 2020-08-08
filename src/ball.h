#ifndef BALL_H
#define BALL_H

#include "SDL.h"

const int BALL_WIDTH = 15;
const int BALL_HEIGHT = 15;
const float BALL_SPEED = 1.0f;

class Ball
{
    public:

        Ball(float x, float y, float vel_x, float vel_y);
        SDL_Rect rect{};
        void Draw(SDL_Renderer* renderer);
        void Update();
        float GetXCoord() {return x;};
        float GetYCoord() {return y;};
        void ChangeXDir() {vel_x = vel_x * -1.0;};
        void ChangeYDir() {vel_y = vel_y * -1.0;};
        void ResetBall(const std::size_t screen_width, const std::size_t screen_height);
        private:
            float x, y;
            float vel_x, vel_y;
            //Vector2D velocity;
            SDL_Renderer* m_renderer;

};
#endif