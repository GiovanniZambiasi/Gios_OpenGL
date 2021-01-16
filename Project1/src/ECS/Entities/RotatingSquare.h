#pragma once
#include "../Entity.h"

namespace Gio::ECS::Entities
{
    class RotatingSquare : public Entity
    {
    public:
        RotatingSquare(Color color, Vector3 position);

        ~RotatingSquare();
        
        void OnUpdate(float deltaTime) override;
    };
}