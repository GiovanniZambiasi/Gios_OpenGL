#include <GL/glew.h>
#include <stdexcept>

#include "ObjectRenderer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

Gio::ECS::Components::ObjectRenderer::ObjectRenderer(Entity& entity, float vertices[], float vertexBufferSize, unsigned int indices[],
    unsigned indexCount, Color color)
        : Component(entity)
        , _vertexBuffer(Rendering::VertexBuffer(vertices,  vertexBufferSize))
        , _bufferLayout (Rendering::VertexBufferLayout())
        , _vertexArray(Rendering::VertexArray())
        , _indexBuffer(Rendering::IndexBuffer(indices, indexCount))
        , _shader( Rendering::Shader("res/Shaders/Basic.shader"))
        , _color(color) 
{
    _bufferLayout.Push<float>(2);

    _vertexArray.AddBuffer(_vertexBuffer, _bufferLayout);
    
    _shader.Bind();
    _shader.SetUniform4f("u_Color", _color.r, _color.g, _color.b, _color.a);
    
    _vertexArray.UnBind();
    _vertexBuffer.UnBind();
    _indexBuffer.UnBind();
    _shader.UnBind();
}

Gio::ECS::Components::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::Components::ObjectRenderer::Draw()
{    
    Renderer::Draw(entity.GetTransform(), _vertexArray, _indexBuffer, _shader);
}
