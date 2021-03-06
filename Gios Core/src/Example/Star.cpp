﻿#include "Star.h"

#include "../../Input.h"
#include "../../Time.h"
#include "../../Rendering/ShaderManager.h"
#include "../../Rendering/Primitives/Square.h"
#include "../ECS/Components/ObjectRenderer.h"
#include "../ECS/Components/Rotator.h"

Gio::Example::Star::Star(Color color, Vector3 position)
    : Entity("Star")
    , _scale(Random::Between(2.0f, 3.0f))
    , _offset(Random::Between(0.0f, 10.0f))
    , _twinkleSpeed(Random::Between(2.0f, 5.0f))
{
    auto mesh = Rendering::Primitives::Square::GetOneByOne();
    
    auto material = new Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));
    
    auto renderer = new ECS::Components::ObjectRenderer(*this, *mesh, *material);
    
    auto rotator = new ECS::Components::Rotator(*this, 180.0f);

    AddComponent(renderer);
    AddComponent(rotator);

    SetColor(color);
    
    Transform& transform = GetTransform();
    transform.SetPosition(position);
    transform.SetScale(Vector3::One() * _scale);
}

Gio::Example::Star::~Star()
{
    auto renderer = GetComponent<ECS::Components::ObjectRenderer>();
    delete &(renderer->GetMaterial());
}

void Gio::Example::Star::OnUpdate(float deltaTime)
{
    auto scaleFactor = Math::Sin((_offset + Time::GetTimeSinceStartSeconds()) * _twinkleSpeed);

    GetTransform().SetScale(Vector3::One() * scaleFactor * _scale);
}

void Gio::Example::Star::SetColor(Color color)
{
    auto renderer = GetComponent<ECS::Components::ObjectRenderer>();
    renderer->GetMaterial().SetColor("u_Color", color);
}