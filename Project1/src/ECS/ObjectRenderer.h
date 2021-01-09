#pragma once

#include <vector>
#include "Component.h"
#include "../Color.h";
#include "../Entity.h"
#include "../Vector2.h";

namespace Gio::ECS
{
    class ObjectRenderer : public Component
    {
    private:
        std::vector<Vector2>* _vertices;
        Color _color;
        
    public:
        ObjectRenderer(Transform* transform, std::vector<Vector2>* vertices, Color color);

        ~ObjectRenderer();
        
        void LateUpdate(float deltaTime) override;
    };
}