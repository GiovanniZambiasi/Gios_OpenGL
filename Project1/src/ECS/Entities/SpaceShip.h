#pragma once
#include "../Entity.h"
#include "../../InputSystem/InputAxis.h"

namespace Gio::ECS::Entities
{
    class SpaceShip : public Entity
    {
    private:
        InputSystem::InputAxis* _horizontal;
        InputSystem::InputAxis* _vertical;
        float _throttleSpeed;
        float _rotationSpeed;
        float _rotationVelocity;
    
    public:
        SpaceShip();

        ~SpaceShip();
        
        void OnUpdate(float deltaTime) override;

    private:
        void UpdateThrottle(float deltaTime);

        void UpdateRotation(float deltaTime);
    };
}
