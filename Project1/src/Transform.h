#pragma once
#include "Math.h"
#include "Vector3.h"

namespace Gio
{
    class Transform
    {
    private:
        Vector3 _scale;
        
    public:
        Vector3 position;
        Vector3 rotationEuler;
        
        Transform();
        
        ~Transform();

        Vector3 GetScale() { return _scale; }
        
        Vector3 GetUp();
        
        Vector3 GetForward();

        Vector3 GetRotationRadians() { return Vector3(Math::DegreesToRadians(rotationEuler.x), Math::DegreesToRadians(rotationEuler.y), Math::DegreesToRadians(rotationEuler.z)); }

        void Translate(Vector3 translation);

        void SetPosition(Vector3 position) { this->position = position; }
        
        void Rotate(Vector3 rotation);

        void SetScale(Vector3 scale) { _scale = scale; }
    };
}
