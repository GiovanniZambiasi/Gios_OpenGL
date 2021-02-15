#pragma once
#include "Math.h"
#include "Vector3.h"

namespace Gio
{
    class Transform
    {
    private:
        Vector3 _scale;
        Vector3 _position;
        Vector3 _rotationEuler;
    public:
        
        Transform();
        
        ~Transform();

        Vector3 GetPosition() { return _position; }

        Vector3 GetRotationEuler() { return _rotationEuler; }
        
        Vector3 GetScale() { return _scale; }
        
        Vector3 GetUp();
        
        Vector3 GetForward();

        Vector3 GetRotationRadians() { return Vector3(Math::DegreesToRadians(_rotationEuler.x), Math::DegreesToRadians(_rotationEuler.y), Math::DegreesToRadians(_rotationEuler.z)); }

        void Translate(Vector3 translation);

        void SetPosition(Vector3 position) { _position = position; }

        void SetRotation(Vector3 rotation) { _rotationEuler = rotation; }
        
        void Rotate(Vector3 rotation);

        void SetScale(Vector3 scale) { _scale = scale; }

        Vector3 TransformPoint(Vector3 point);
    };
}
