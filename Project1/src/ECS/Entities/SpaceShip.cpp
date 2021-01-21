#include "SpaceShip.h"

#include "../../Input.h"
#include "../../Rendering/ShaderManager.h"
#include "../Components/ObjectRenderer.h"

Gio::ECS::Entities::SpaceShip::SpaceShip()
    : Entity("Space Ship")
    , _throttleSpeed(150.0f)
    , _rotationVelocity(0.0f)
    , _rotationSpeed(180.0f)
{
    float vertices[] =
        {
        0.0f, 1.0f, 0.0f,
        -.75f, -1.0f, 0.0f,
        0.0f, -0.66f, 0.0f,
        .75f, -1.0f, 0.0f
    };
    unsigned int indices[]
    {
        0, 1, 2,
        2, 3, 0
    };
    auto mesh = new Rendering::Mesh(vertices , 4, indices, 6);

    auto material = new Rendering::Material(*Rendering::ShaderManager::GetShader("Basic"));
    
    material->SetColor("u_Color", Color(.0f, .0f, .9f, 1.0f));
    
    auto renderer = new Components::ObjectRenderer(*this, *mesh, *material);

    AddComponent(renderer);

    _horizontal = Input::GetActionManager()->GetAxis("Horizontal");
    _vertical = Input::GetActionManager()->GetAxis("Vertical");

    GetTransform().SetScale(Vector3::One() * 35.0f);
}

Gio::ECS::Entities::SpaceShip::~SpaceShip()
{
}

void Gio::ECS::Entities::SpaceShip::OnUpdate(float deltaTime)
{
    UpdateThrottle(deltaTime);
    UpdateRotation(deltaTime);

    Camera::instance->GetTransform().SetPosition(GetTransform().GetPosition());
}

void Gio::ECS::Entities::SpaceShip::UpdateThrottle(float deltaTime)
{
    auto throttle = _vertical->GetValue();
    
    Transform& transform = GetTransform();
    auto movement = transform.GetUp();

    movement = movement * (throttle * _throttleSpeed * deltaTime); 
    GetTransform().Translate(movement);
}

void Gio::ECS::Entities::SpaceShip::UpdateRotation(float deltaTime)
{
    auto input = _horizontal->GetValue();
    auto rotation = Vector3::Forward() * (-input * deltaTime * _rotationSpeed);

    Transform& transform = GetTransform();
    transform.Rotate(rotation);
}