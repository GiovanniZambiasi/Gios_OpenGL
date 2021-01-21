#include "MovingRotatingSquare.h"
#include "../../Input.h"

Gio::ECS::Entities::MovingRotatingSquare::MovingRotatingSquare(const Color& color, const Vector3& position,
                                                               float movementSpeed)
    : Star(color, position)
    , _movementSpeed(movementSpeed)
{
    SetName("Moving & Rotating Square");
    
    _colorChange = Input::GetActionManager()->GetAction("ColorChange");
    
    _moveHorizontal = Input::GetActionManager()->GetAxis("Horizontal");

    _moveVertical = Input::GetActionManager()->GetAxis("Vertical");

    _spawnCube = Input::GetActionManager()->GetAction("SpawnCube");
}

Gio::ECS::Entities::MovingRotatingSquare::~MovingRotatingSquare()
{
}

void Gio::ECS::Entities::MovingRotatingSquare::OnUpdate(float deltaTime)
{
    if(_spawnCube->WasPressedThisFrame())
    {
        new Star(Color::Random(), GetTransform().GetPosition());
    }
    
    if(_colorChange->WasPressedThisFrame())
    {
        SetColor(Color::Random());
    }

    if(_moveHorizontal!= nullptr && _moveVertical != nullptr)
    {
        Vector3 movement = Vector3(_moveHorizontal->GetValue(), _moveVertical->GetValue(), 0.0f);
        movement = Vector3::ClampMagnitude(movement, 1.0f);
        GetTransform().Translate(movement * _movementSpeed * deltaTime);
    }

    Camera::instance->GetTransform().SetPosition(GetTransform().GetPosition());
}