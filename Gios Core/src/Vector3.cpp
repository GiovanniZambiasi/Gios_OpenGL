#include "Vector3.h"
#include "Math.h"

Gio::Vector3::Vector3(float x, float y, float z)
    : Vector2(x, y)
    , z(z)
{
}

Gio::Vector3::Vector3()
{
}

float Gio::Vector3::GetMagnitude()
{
    return Math::Sqrt(Math::Pow(x, 2) + Math::Pow(y, 2) + Math::Pow(z, 2));
}

std::string Gio::Vector3::to_string()
{
    return "(X: " + std::to_string(x) + " Y: " + std::to_string(y) + " Z: " + std::to_string(z) + ")";
}

void Gio::Vector3::Normalize()
{
    *this = this->Normalized();
}

Gio::Vector3 Gio::Vector3::Normalized()
{
    float magnitude = GetMagnitude();
    return magnitude == 0 ?
        Zero() :
        Vector3(x/magnitude, y/magnitude, z/magnitude);
}

Gio::Vector3 Gio::Vector3::ClampMagnitude(Vector3 vector, float magnitude)
{
    if(vector.GetMagnitude() > magnitude)
    {
        vector.Normalize();
        vector = vector * magnitude;
    }

    return vector;
}
