#include "SpaceShip.h"

#include "../../Input.h"
#include "../../Rendering/ShaderManager.h"
#include "../ECS/Components/ObjectRenderer.h"

Gio::Example::SpaceShip::SpaceShip()
    : Entity("Space Ship")
    , _thrusterSpeed(150.0f)
    , _rotationSpeed(360.0f)
    , _rotationVelocity(0.0f)
    , _drag(100.0f)
    , _angularDrag(180.0f)
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
    
    auto renderer = new ECS::Components::ObjectRenderer(*this, *mesh, *material);

    AddComponent(renderer);

    _physics = new ECS::Components::Physics(*this, 1.0f, _drag, _angularDrag);

    AddComponent(_physics);

    _horizontal = Input::GetActionManager()->GetAxis("Horizontal");
    _vertical = Input::GetActionManager()->GetAxis("Vertical");

    _boost = Input::GetActionManager()->GetAction("Boost");
    _changeColor = Input::GetActionManager()->GetAction("Change Color");
    
    GetTransform().SetScale(Vector3::One() * 35.0f);
}

Gio::Example::SpaceShip::~SpaceShip()
{
}

void Gio::Example::SpaceShip::OnUpdate(float deltaTime)
{
    UpdateThrottle(deltaTime);
    UpdateRotation(deltaTime);

    if(_changeColor->WasPressedThisFrame())
    {
        auto renderer = GetComponent<ECS::Components::ObjectRenderer>();
        renderer->GetMaterial().SetColor("u_Color", Color::Random());
    }

    Camera::instance->GetTransform().SetPosition(GetTransform().GetPosition());
}

void Gio::Example::SpaceShip::UpdateThrottle(float deltaTime)
{
    auto throttle = _vertical->GetValue();

    _physics->SetDrag(Math::Abs(throttle) > .01f ? _drag : _drag * 3.0f);

    Transform& transform = GetTransform();
    auto movement = transform.GetUp();

    float speed = _boost->IsPressed() ? _thrusterSpeed * 3.0f : _thrusterSpeed;

    movement = movement * (speed * throttle * deltaTime);

    _physics->AddForce(movement);
}

void Gio::Example::SpaceShip::UpdateRotation(float deltaTime)
{
    auto input = _horizontal->GetValue();

    _physics->SetAngularDrag(Math::Abs(input) > .01f ? _angularDrag : _angularDrag * 2.0f);

    auto rotation = Vector3::Forward() * (-input * deltaTime * _rotationSpeed);

    _physics->AddTorque(rotation);
}