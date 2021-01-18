#include "RotatingSquare.h"

#include "../../Random.h"
#include "../../Input/Input.h"
#include "../../Input/Devices/Keyboard.h"
#include "../../Input/Devices/KeyboardKey.h"
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

    material->SetColor("u_Color", color);
    
    AddComponent(renderer);
    AddComponent(rotator);

    Transform& transform = GetTransform();
    transform.position = position;
    transform.SetScale(Vector3::One() * 50.0f);
}

Gio::ECS::Entities::RotatingSquare::~RotatingSquare()
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    delete &(renderer->GetMaterial());
}

void Gio::ECS::Entities::RotatingSquare::OnUpdate(float deltaTime)
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    
    Input::Devices::Keyboard* keyboard = Input::Input::instance->GetDevice<Input::Devices::Keyboard>();
    if(keyboard != nullptr)
    {
        if(keyboard->GetKey(Input::Devices::KeyboardKey::Space)->WasPressedThisFrame())
        {
            renderer->GetMaterial().SetColor("u_Color", Random::Color());
        }

        Vector3 movement;
        if(keyboard->GetKey(Input::Devices::KeyboardKey::A)->IsPressed() || keyboard->GetKey(Input::Devices::KeyboardKey::D)->IsPressed())
        {
            movement.x =  keyboard->GetKey(Input::Devices::KeyboardKey::D)->IsPressed() ? 1 : -1; 
        }
        if(keyboard->GetKey(Input::Devices::KeyboardKey::W)->IsPressed() || keyboard->GetKey(Input::Devices::KeyboardKey::S)->IsPressed())
        {
            movement.y =  keyboard->GetKey(Input::Devices::KeyboardKey::W)->IsPressed() ? 1 : -1; 
        }

        movement = Vector3::ClampMagnitude(movement, 1.0f);

        GetTransform().Translate(movement * _movementSpeed);
    }
}

void Gio::ECS::Entities::RotatingSquare::OnDraw(Renderer& renderer)
{
    renderer.DrawLine(Vector3::Zero(), Vector3::Up() * 10000, Color::Red());
}
