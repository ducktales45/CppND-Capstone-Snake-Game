#include "vector2D.h"
#include "SDL.h"

const int BALL_WIDTH = 30;
const int BALL_HEIGHT = 30;

class Ball
{
    public:

        Ball(Vector2D location);
        SDL_Rect rect{};
        void Draw(SDL_Renderer* renderer);
        private:
            Vector2D location;
            
            SDL_Renderer* m_renderer;

};