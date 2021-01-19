#pragma once
#include "../Entity.h"
#include "../../InputSystem/InputAction.h"
#include "../../InputSystem/InputAxis.h"

namespace Gio::ECS::Entities
{
    class RotatingSquare : public Entity
    {
    private:
        InputSystem::InputAction* _colorChange;
        InputSystem::InputAxis* _moveHorizontal;
        InputSystem::InputAxis* _moveVertical;
        float _movementSpeed = 5.0f;
    
    public:
        RotatingSquare(Color color, Vector3 position);

        ~RotatingSquare();
        
        void OnUpdate(float deltaTime) override;
        
        void OnDraw(Renderer& renderer) override;
    };
}
