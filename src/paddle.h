#ifndef PADDLE_H
#define PADDLE_H

#include "SDL.h"

const int PADDLE_WIDTH = 20;
const int PADDLE_HEIGHT = 100;
const int WINDOW_HEIGHT = 640;

class Paddle
{
    public:

        enum class Direction { kUp, kDown, kNone };
        Paddle(float x, float y, float vel_y);
        Direction direction = Direction::kUp;
        void Draw(SDL_Renderer* renderer);
        void Update();
        float GetXCoord() {return x;};
        float GetYCoord() {return y;};
        //Vector2D GetLocation();
    private:
        float x, y;
        float vel_y;
        SDL_Rect rect{};

};

#endif