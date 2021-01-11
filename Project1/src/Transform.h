#pragma once
#include "Vector3.h"

namespace Gio
{
    class Transform
    {
    public:
        Vector3 position;
        Vector3 rotation;
        
        Transform();
        
        ~Transform();
        
        Vector3 GetUp();
        
        Vector3 GetForward();
        
        void Translate(Vector3 translation);
        
        void Rotate(Vector3 rotation);
    };
}
