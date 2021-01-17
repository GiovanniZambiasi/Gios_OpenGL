#pragma once

#include "../Component.h"
#include "../Entity.h"
#include "../../Renderer.h"
#include "../../Rendering/Material.h"
#include "../../Rendering/Mesh.h"

namespace Gio::ECS::Components
{
    class ObjectRenderer : public Component
    {
    private:
        Rendering::Mesh& _mesh;
        Rendering::Material& _material;
        
    public:
        ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Rendering::Material& material);

        ~ObjectRenderer();

        void Draw(Renderer& renderer) override;

        Gio::Rendering::Material& GetMaterial() { return _material; }
    };
}
