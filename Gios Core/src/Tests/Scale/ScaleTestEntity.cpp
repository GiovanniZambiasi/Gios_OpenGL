#include "ScaleTestEntity.h"

#include "../../ECS/Components/ObjectRenderer.h"
#include "../../Rendering/ShaderManager.h"
#include "../../Rendering/Primitives/Square.h"

Gio::Tests::Scale::ScaleTestEntity::ScaleTestEntity()
    : Entity("Square")
{
    auto material = new Gio::Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));
    material->SetColor("u_Color", Color::White());
    
    auto renderer = new ECS::Components::ObjectRenderer(*this, *Rendering::Primitives::Square::GetOneByOne(), *material);

    AddComponent(renderer);
}

Gio::Tests::Scale::ScaleTestEntity::~ScaleTestEntity()
{
}
