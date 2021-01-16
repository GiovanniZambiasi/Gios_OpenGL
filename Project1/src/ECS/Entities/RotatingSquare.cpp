#include "RotatingSquare.h"

#include "../../Input/Input.h"
#include "../../Input/Devices/Keyboard.h"
#include "../../Rendering/Primitives/Square.h"
#include "../Components/ObjectRenderer.h"
#include "../Components/Rotator.h"

Gio::ECS::Entities::RotatingSquare::RotatingSquare(Color color, Vector3 position)
    : Entity("Rotating Square")
{
    auto mesh = new Rendering::Primitives::Square(1.0f, 1.0f);
    
    auto renderer = new Components::ObjectRenderer(*this, *mesh, color);
    auto rotator = new Components::Rotator(*this);

    AddComponent(renderer);
    AddComponent(rotator);

    Transform& transform = GetTransform();
    transform.position = position;
    transform.SetScale(Vector3::One() * 100.0f);
}

Gio::ECS::Entities::RotatingSquare::~RotatingSquare()
{
}

void Gio::ECS::Entities::RotatingSquare::OnUpdate(float deltaTime)
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    
    Input::Devices::Keyboard* keyboard = Input::Input::instance->GetDevice<Input::Devices::Keyboard>();
    if(keyboard != nullptr)
    {
        if(keyboard->GetKey(Input::Devices::KeyboardKey::Space)->WasPressedThisFrame())
        {
            renderer->GetMaterial().SetColor("u_Color", Color::White());
        }
    }
}
