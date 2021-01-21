#pragma once
#include "Star.h"
#include "../../InputSystem/InputAction.h"
#include "../../InputSystem/InputAxis.h"

namespace Gio::ECS::Entities
{
    class MovingRotatingSquare : public Star
    {
    private:
        InputSystem::InputAction* _colorChange;
        InputSystem::InputAction* _spawnCube;
        InputSystem::InputAxis* _moveHorizontal;
        InputSystem::InputAxis* _moveVertical;
        float _movementSpeed;
    
    public:

        MovingRotatingSquare(const Color& color, const Vector3& position, float movementSpeed);

        ~MovingRotatingSquare();

        void OnUpdate(float deltaTime) override;
    };
}
