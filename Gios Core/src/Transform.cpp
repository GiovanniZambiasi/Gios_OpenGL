#include "Transform.h"
#include "../Debug.h"

Gio::Transform::Transform()
    : _position(Vector3())
    , _rotationEuler(Vector3())
    , _scale(Vector3::One())
{
}

Gio::Transform::~Transform()
{
}

Gio::Vector3 Gio::Transform::GetUp()
{
    Vector3 up = Vector3::Up();
    
    float angle = _rotationEuler.z;
    
    up.Rotate(angle);
 
    return up;
}

Gio::Vector3 Gio::Transform::GetForward()
{
    Vector3 fwd = Vector3::Forward();

    Debug::LogWarning("Transform.GetForward() not implemented!");
    
    return fwd;    
}

void Gio::Transform::Translate(Vector3 translation)
{
    _position = _position + translation;
}

void Gio::Transform::Rotate(Vector3 rotation)
{
    this->_rotationEuler = this->_rotationEuler + rotation;
}
