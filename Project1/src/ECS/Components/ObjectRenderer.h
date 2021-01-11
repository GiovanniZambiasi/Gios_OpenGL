#pragma once

#include "../Component.h"
#include "../Color.h";
#include "../Entity.h"
#include "IndexBuffer.h"
#include "../Renderer.h"

namespace Gio::ECS::Components
{
    class ObjectRenderer : public Component
    {
    private:
        Rendering::VertexBuffer _vertexBuffer;
        Rendering::VertexBufferLayout _bufferLayout;
        Rendering::VertexArray _vertexArray;
        Rendering::IndexBuffer _indexBuffer;
        Rendering::Shader _shader;
        
        Color _color;
        
    public:
        ObjectRenderer(Entity& entity, float vertices[], float vertexBufferSize, unsigned int indices[], unsigned indexCount, Color color);

        ~ObjectRenderer();
        
        void Draw() override;
    };
}