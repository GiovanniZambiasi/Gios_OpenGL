#pragma once
#include "../Entity.h"

namespace Gio::ECS::Entities
{
    class RotatingSquare : public Entity
    {
    private:
        float _movementSpeed = 5.0f;
    
    public:
        RotatingSquare(Color color, Vector3 position);

        ~RotatingSquare();
        
        void OnUpdate(float deltaTime) override;
        
        void OnDraw(Renderer& renderer) override;
    };
}