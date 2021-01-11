#pragma once
#include "Transform.h"

namespace Gio
{
    class Camera
    {
    private:
        Camera();

        ~Camera();

        inline static Transform* _transform = new Transform();
    
    public:
        static Transform& GetTransform() { return *_transform; }
        
        static void Initialize();
    };
}
