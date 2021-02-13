#pragma once
#include "../../InputSystem/InputAction.h"
#include "../../InputSystem/InputAxis.h"
#include "../ECS/Entity.h"
#include "../ECS/Components/Physics.h"

namespace Gio::Example
{
    class SpaceShip : public ECS::Entity
    {
    private:
        InputSystem::InputAxis* _horizontal;
        InputSystem::InputAxis* _vertical;
        InputSystem::InputAction* _boost;
        InputSystem::InputAction* _changeColor;
        InputSystem::InputAction* _shoot;
        ECS::Components::Physics* _physics;
        float _thrusterSpeed;
        float _rotationSpeed;
        float _rotationVelocity;
        float _drag;
        float _angularDrag;
    
    public:
        SpaceShip();

        ~SpaceShip();
    
    protected:
        
        void OnUpdate(float deltaTime) override;
    
    private:
        void UpdateThrottle(float deltaTime);

        void UpdateRotation(float deltaTime);

        void Shoot();
    };
}
