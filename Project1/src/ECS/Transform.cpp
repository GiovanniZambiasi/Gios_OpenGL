#include "Transform.h"

Gio::Transform::Transform()
    : position(Vector3())
    , rotation(Vector3())
{
}

Gio::Transform::~Transform()
{
}

Gio::Vector3 Gio::Transform::GetUp()
{
    Vector3 up = Vector3::Up();
    
    float angle = rotation.z;
    
    up.Rotate(angle);
 
    return up;
}

void Gio::Transform::Translate(Vector3 translation)
{
    position = position + translation;
}

void Gio::Transform::Rotate(Vector3 rotation)
{
    this->rotation = this->rotation + rotation;
}
