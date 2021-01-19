#pragma once
#include "../Entity.h"
#include "../../Input/InputAction.h"
#include "../../Input/InputAxis.h"

namespace Gio::ECS::Entities
{
    class RotatingSquare : public Entity
    {
    private:
        Input::InputAction* _colorChange;
        Input::InputAxis* _moveHorizontal;
        Input::InputAxis* _moveVertical;
        float _movementSpeed = 5.0f;
    
    public:
        RotatingSquare(Color color, Vector3 position);

        ~RotatingSquare();
        
        void OnUpdate(float deltaTime) override;
        
        void OnDraw(Renderer& renderer) override;
    };
}
