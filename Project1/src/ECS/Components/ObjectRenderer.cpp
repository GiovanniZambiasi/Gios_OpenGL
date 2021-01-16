#include "ObjectRenderer.h"
#include "ShaderManager.h"

Gio::ECS::Components::ObjectRenderer::ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Color color)
        : Component(entity)
        , _mesh(mesh)
{
    Rendering::Shader* shader = Rendering::ShaderManager::GetShader("Basic");

    if(shader == nullptr)
    {
        Debug::LogError("Shader could not be found");
        return;
    }
    
    _material = new Rendering::Material(*shader);
    _material->SetColor("u_Color", color);
}

Gio::ECS::Components::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::Components::ObjectRenderer::Draw(Renderer& renderer)
{
    renderer.Draw(entity.GetTransform(), _mesh, *_material);
}