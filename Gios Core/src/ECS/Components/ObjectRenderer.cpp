#include "ObjectRenderer.h"
#include "..\Rendering\ShaderManager.h"

Gio::ECS::Components::ObjectRenderer::ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Rendering::Material& material)
        : Component(entity)
        , _mesh(mesh)
        , _material(material)
{
}

Gio::ECS::Components::ObjectRenderer::~ObjectRenderer()
{
}

void Gio::ECS::Components::ObjectRenderer::Draw(Renderer& renderer)
{
    renderer.Draw(entity.GetTransform(), _mesh, _material);
}