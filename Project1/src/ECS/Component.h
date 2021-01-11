#pragma once
#include "Entity.h"

namespace Gio::ECS
{
    class Component
    {
    protected:
        Entity& entity;
        
        Component(Entity& entity);

    public:
        
        virtual void Update(float deltaTime) {}

        virtual void Draw() {}
    };
}
