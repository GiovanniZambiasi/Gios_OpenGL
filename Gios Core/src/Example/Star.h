#pragma once
#include "../ECS/Entity.h"

namespace Gio::Example
{
    class Star : public ECS::Entity
    {
    private:
        float _scale;
        float _offset;
        float _twinkleSpeed;
    
    public:
        Star(Color color, Vector3 position);

        ~Star();

        void SetColor(Color color);

    protected:

        void OnUpdate(float deltaTime) override;
        
    };
}
