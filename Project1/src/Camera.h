#pragma once
#include "Transform.h"

namespace Gio
{
    class Camera
    {
    private:
        Transform _transform;
    
    public:
        Camera();

        ~Camera();

        Transform& GetTransform() { return _transform; }
    };
}
