#pragma once
#include "../Entity.h"

namespace Gio::ECS::Entities
{
    class RotatingSquare : public Entity
    {
    public:
        RotatingSquare(Color color, Vector3 position, float scale);

        ~RotatingSquare();
        
        void OnDraw(Renderer& renderer) override;
    
        void SetColor(Color color);    
    };
}