#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D
{
    float x, y;

    Vector2D(float x, float y) : x(x), y(y) {};

    // override + operator for vector addition
    Vector2D operator+(Vector2D const& vec)
    {
        return Vector2D(x + vec.x, y + vec.y);
    }

    Vector2D& operator+=(Vector2D const& vec)
    {
        x += vec.x;
        x += vec.y;
        return *this;
    }

    Vector2D operator*(float vec)
    {
        return Vector2D(x * vec, y * vec);
    }

};
#endif