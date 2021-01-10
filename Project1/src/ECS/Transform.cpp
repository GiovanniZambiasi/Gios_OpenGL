#include "Transform.h"

Gio::Transform::Transform()
    : position(Vector2())
    , rotation(Vector3())
{
}

Gio::Transform::~Transform()
{
}

Gio::Vector2 Gio::Transform::GetUp()
{
    Vector2 forward = Vector2::Up();
    
    float angle = rotation.z;
    
    forward.Rotate(angle);
    
    return forward.GetNormalized();
}

void Gio::Transform::Translate(Vector2 translation)
{
    position = position + translation;
}

void Gio::Transform::Rotate(Vector3 rotation)
{
    this->rotation = this->rotation + rotation;
}
