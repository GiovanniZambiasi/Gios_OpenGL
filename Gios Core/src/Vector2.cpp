#include "Vector2.h"
#include "Math.h"

Gio::Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Gio::Vector2::Vector2()
{
    x = 0.0f;
    y = 0.0f;
}

Gio::Vector2::~Vector2()
{
}

void Gio::Vector2::Rotate(float degrees)
{
    float rX = x * Math::Cos(degrees) - y * Math::Sin(degrees);
    float rY = x * Math::Sin(degrees) + y * Math::Cos(degrees);

    x = rX;
    y = rY;
}

float Gio::Vector2::GetMagnitude()
{
    return Math::Sqrt(Math::Pow(x, 2) + Math::Pow(y, 2));
}

void Gio::Vector2::Normalize()
{
    float magnitude = GetMagnitude();
    x /= magnitude;
    y /= magnitude;
}

std::string Gio::Vector2::to_string()
{
    return std::string("(X: " + std::to_string(x) + " Y: " + std::to_string(y) + ")");
}
