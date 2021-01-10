#pragma once
#include "../Vector2.h"
#include "../Vector3.h"

namespace Gio
{
    class Transform
    {
    public:
        Vector2 position;
        Vector3 rotation;
        
        Transform();
        
        ~Transform();
        
        Vector2 GetUp();

        void Translate(Vector2 translation);
        
        void Rotate(Vector3 rotation);
    };
}
