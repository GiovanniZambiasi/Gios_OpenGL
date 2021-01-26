#pragma once
#include "../Component.h"

namespace Gio::ECS::Components
{
    class Rotator : public Component
    {
    private:
        float _rotationSpeed;
    public:
        Rotator(Entity& entity, float rotationSpeed)
            : Component(entity)
            , _rotationSpeed(rotationSpeed)
        {
        }

        ~Rotator(){}

        void Update(float deltaTime) override;
    };
}
