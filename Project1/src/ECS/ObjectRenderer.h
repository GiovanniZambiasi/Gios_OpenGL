#pragma once

#include <vector>
#include "Component.h"
#include "../Color.h";
#include "Entity.h"
#include "IndexBuffer.h"
#include "../Vector2.h";
#include "../Renderer.h"

namespace Gio::ECS
{
    class ObjectRenderer : public Component
    {
    private:
        /*Rendering::IndexBuffer* _indexBuffer;
        Rendering::VertexArray* _vertexArray;
        Rendering::VertexArray* _vertexArray;*/
        std::vector<Vector2> _vertices;
        Color _color;
        
    public:
        ObjectRenderer(Entity* entity, std::vector<Vector2> vertices, Color color);

        ~ObjectRenderer();
        
        void LateUpdate(float deltaTime) override;
    };
}