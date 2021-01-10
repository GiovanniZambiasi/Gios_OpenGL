#include "Vector3.h"

Gio::Vector3::Vector3(float x, float y, float z)
    : Vector2(x, y)
    , z(z)
{
}

Gio::Vector3::Vector3()
{
}

Gio::Vector3::~Vector3()
{
}

Gio::Vector3 Gio::Vector3::GetNormalized()
{
    float magnitude = GetMagnitude();
    return Vector3(x/magnitude, y/magnitude, z/magnitude);
}

float Gio::Vector3::GetMagnitude()
{
    return Vector2::GetMagnitude() + std::abs(z);
}

std::string Gio::Vector3::to_string()
{
    return "(X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + ")";
}
