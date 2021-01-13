#pragma once

#include "../Component.h"
#include "../Entity.h"
#include "../../Color.h"
#include "../../Rendering/Mesh.h"
#include "../../Rendering/Shader.h"

namespace Gio::ECS::Components
{
    class ObjectRenderer : public Component
    {
    private:
        Rendering::Mesh& _mesh;
        Rendering::Shader _shader;
        
        Color _color;
        
    public:
        ObjectRenderer(Entity& entity, Rendering::Mesh& mesh, Color color);

        ~ObjectRenderer();

        void SetColor(Color color);
        
        void Draw(Renderer& renderer) override;
    };
}
