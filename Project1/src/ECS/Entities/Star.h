#pragma once
#include "../Entity.h"

namespace Gio::ECS::Entities
{
    class Star : public Entity
    {
    private:
        float _scale;
        float _offset;
        float _twinkleSpeed;
    
    public:
        Star(Color color, Vector3 position);

        ~Star();

        void OnUpdate(float deltaTime) override;
        
        void OnDraw(Renderer& renderer) override;

        void SetColor(Color color);
    };
}