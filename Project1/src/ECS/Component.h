#pragma once
#include "../Transform.h"

namespace Gio::ECS
{
    class Component
    {
    protected:
        Transform* transform = nullptr;
        
        Component(Transform* transform);

    public:
        
        virtual void Update(float deltaTime) {}

        virtual void LateUpdate(float deltaTime) {}
    };
}
