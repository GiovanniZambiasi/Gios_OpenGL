#include "ObjectRenderer.h"
#include "../../Renderer.h"

Gio::ECS::Components::ObjectRenderer::ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Color color)
        : Component(entity)
        , _mesh(mesh)
        , _shader( Rendering::Shader("res/Shaders/Basic.shader"))
{
    SetColor(color);
}

Gio::ECS::Components::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::Components::ObjectRenderer::SetColor(Color color)
{
    _color = color;

    _shader.Bind();
    _shader.SetUniform4f("u_Color", _color.r, _color.g, _color.b, _color.a);
    _shader.UnBind();
}

void Gio::ECS::Components::ObjectRenderer::Draw()
{    
    Renderer::Draw(entity.GetTransform(), _mesh, _shader);
}
