#include "RotatingSquare.h"

#include "../../Input.h"
#include "../../Rendering/ShaderManager.h"
#include "../../Rendering/Primitives/Square.h"
#include "../Components/ObjectRenderer.h"
#include "../Components/Rotator.h"

Gio::ECS::Entities::RotatingSquare::RotatingSquare(Color color, Vector3 position)
    : Entity("Rotating Square")
{
    auto mesh = new Rendering::Primitives::Square(1.0f, 1.0f);

    auto material = new Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));
    auto renderer = new Components::ObjectRenderer(*this, *mesh, *material);
    auto rotator = new Components::Rotator(*this, 180.0f);

    AddComponent(renderer);
    AddComponent(rotator);

    SetColor(color);
    
    Transform& transform = GetTransform();
    transform.position = position;
    transform.SetScale(Vector3::One() * 50.0f);
}

Gio::ECS::Entities::RotatingSquare::~RotatingSquare()
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    delete &(renderer->GetMaterial());
}

void Gio::ECS::Entities::RotatingSquare::OnDraw(Renderer& renderer)
{
    renderer.DrawLine(Vector3::Zero(), Vector3::Up() * 10000, Color::Red());
}

void Gio::ECS::Entities::RotatingSquare::SetColor(Color color)
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    renderer->GetMaterial().SetColor("u_Color", color);
}