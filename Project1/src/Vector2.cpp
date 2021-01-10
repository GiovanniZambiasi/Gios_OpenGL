#include <valarray>
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
    x = x * std::cos(Math::RadiansToDegrees(degrees)) - y * std::sin(Math::RadiansToDegrees(degrees));
    y = x * std::sin(Math::RadiansToDegrees(degrees)) + y * std::cos(Math::RadiansToDegrees(degrees));
}

float Gio::Vector2::GetMagnitude()
{
    return std::abs(x) + std::abs(y);
}

Gio::Vector2 Gio::Vector2::GetNormalized()
{
    float magnitude = GetMagnitude();
    return Vector2(x/magnitude, y/magnitude);
}

std::string Gio::Vector2::to_string()
{
    return std::string("(X: " + std::to_string(x) + " Y: " + std::to_string(y) + ")");
}
