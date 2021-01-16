#pragma once

#include "../Component.h"
#include "../Entity.h"
#include "../../Color.h"
#include "../../Renderer.h"
#include "../../Rendering/Material.h"
#include "../../Rendering/Mesh.h"

namespace Gio::ECS::Components
{
    class ObjectRenderer : public Component
    {
    private:
        Rendering::Mesh& _mesh;
        Rendering::Material* _material;
        
        Color _color;
        
    public:
        ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Color color);

        ~ObjectRenderer();

        void Draw(Renderer& renderer) override;

        Gio::Rendering::Material& GetMaterial() { return *_material; }
    };
}
