#pragma once
#include "../Component.h"

namespace Gio::ECS::Components
{
    class Rotator : public Component
    {
    public:
        Rotator(Entity& entity)
            : Component(entity)
        {
        }

        ~Rotator(){}

        void Update(float deltaTime) override;
    };
}
