#pragma once
#include "Vector2.h"

namespace Gio
{
    class Transform
    {
    public:
        Transform();
        
        ~Transform();
        
        Vector2 position;
        
        Vector2 rotation;
    };
}
