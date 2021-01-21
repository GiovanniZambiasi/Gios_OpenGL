#include "Star.h"

#include "../../Input.h"
#include "../../Time.h"
#include "../../Rendering/ShaderManager.h"
#include "../../Rendering/Primitives/Square.h"
#include "../Components/ObjectRenderer.h"
#include "../Components/Rotator.h"

Gio::ECS::Entities::Star::Star(Color color, Vector3 position)
    : Entity("Rotating Square")
    , _scale(Random::Between(2.0f, 3.0f))
    , _offset(Random::Between(0.0f, 10.0f))
    , _twinkleSpeed(Random::Between(2.0f, 5.0f))
{
    auto mesh = Rendering::Primitives::Square::GetOneByOne();
    
    auto material = new Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));
    
    auto renderer = new Components::ObjectRenderer(*this, *mesh, *material);
    
    auto rotator = new Components::Rotator(*this, 180.0f);

    AddComponent(renderer);
    AddComponent(rotator);

    SetColor(color);
    
    Transform& transform = GetTransform();
    transform.SetPosition(position);
    transform.SetScale(Vector3::One() * _scale);
}

Gio::ECS::Entities::Star::~Star()
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    delete &(renderer->GetMaterial());
}

void Gio::ECS::Entities::Star::OnUpdate(float deltaTime)
{
    auto scaleFactor = Math::Sin((_offset + Time::GetTimeSinceStartSeconds()) * _twinkleSpeed);

    GetTransform().SetScale(Vector3::One() * scaleFactor * _scale);
}

void Gio::ECS::Entities::Star::OnDraw(Renderer& renderer)
{
    renderer.DrawLine(Vector3::Zero(), Vector3::Up() * 10000, Color::Red());
}

void Gio::ECS::Entities::Star::SetColor(Color color)
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    renderer->GetMaterial().SetColor("u_Color", color);
}