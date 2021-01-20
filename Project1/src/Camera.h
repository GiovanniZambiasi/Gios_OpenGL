#pragma once
#include "Transform.h"
#include "Utilities/Singleton.h"

namespace Gio
{
    class Camera : public Utilities::Singleton<Camera>
    {
    private:
        Transform _transform;
    
    public:
        Camera();

        ~Camera();

        Transform& GetTransform() { return _transform; }
    };
}
