#include "RotatingSquare.h"

#include "../../Input/Input.h"
#include "../../Input/InputAxisBindings.h"
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

    _colorChange = Input::Input::instance->GetAction("ColorChange");
    
    if(_colorChange == nullptr)
    {
        Input::Input::instance->RegisterInputAction(
            Input::InputActionBinding(
                "ColorChange",
                {
                    Input::DeviceElementPair("Keyboard", "Spacebar"),
                }));

        _colorChange = Input::Input::instance->GetAction("ColorChange");
    }

    _moveHorizontal = Input::Input::instance->GetAxis("Horizontal");

    _moveVertical = Input::Input::instance->GetAxis("Vertical");
}

Gio::ECS::Entities::RotatingSquare::~RotatingSquare()
{
    auto renderer = GetComponent<Components::ObjectRenderer>();
    delete &(renderer->GetMaterial());
}

void Gio::ECS::Entities::RotatingSquare::OnUpdate(float deltaTime)
{
    auto renderer = GetComponent<Components::ObjectRenderer>();

    if(_colorChange->WasPressedThisFrame())
    {
        renderer->GetMaterial().SetColor("u_Color", Color::Random());
    }

    if(_moveHorizontal!= nullptr && _moveVertical != nullptr)
    {
        Vector3 movement = Vector3(_moveHorizontal->GetValue(), _moveVertical->GetValue(), 0.0f);
        movement = Vector3::ClampMagnitude(movement, 1.0f);
        GetTransform().Translate(movement * _movementSpeed);
    }
}

void Gio::ECS::Entities::RotatingSquare::OnDraw(Renderer& renderer)
{
    renderer.DrawLine(Vector3::Zero(), Vector3::Up() * 10000, Color::Red());
}
