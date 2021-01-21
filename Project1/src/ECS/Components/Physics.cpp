#include "Physics.h"

void Gio::ECS::Components::Physics::Update(float deltaTime)
{
    ApplyDrag(deltaTime);
    ApplyAngularDrag(deltaTime);

    entity.GetTransform().Translate(_velocity * deltaTime);
    entity.GetTransform().Rotate(_angularVelocity * deltaTime);
}

void Gio::ECS::Components::Physics::AddForce(Vector3 force)
{
    _velocity = _velocity + (force / _mass);
}

void Gio::ECS::Components::Physics::AddTorque(Vector3 torque)
{
    _angularVelocity = _angularVelocity + (torque / _mass);
}

void Gio::ECS::Components::Physics::ApplyDrag(float deltaTime)
{
    if(VelocityIsZero())
        return;
    
    float drag = (_drag / _mass) * deltaTime;

    auto dragVec = _velocity.Normalized() * drag;   // Velocity direction not inverted because drag operation is absolute

    _velocity.x = Math::ApplyDrag(_velocity.x, dragVec.x);
    _velocity.y = Math::ApplyDrag(_velocity.y, dragVec.y);
    _velocity.z = Math::ApplyDrag(_velocity.z, dragVec.z);
}

bool Gio::ECS::Components::Physics::VelocityIsZero()
{
    return _velocity.x == 0 && _velocity.y == 0 && _velocity.z == 0;
}

void Gio::ECS::Components::Physics::ApplyAngularDrag(float deltaTime)
{
    float drag = (_angularDrag / _mass) * deltaTime;

    auto dragVec = _angularVelocity.Normalized() * drag;   // Velocity direction not inverted because drag operation is absolute

    _angularVelocity.x = Math::ApplyDrag(_angularVelocity.x, dragVec.x);
    _angularVelocity.y = Math::ApplyDrag(_angularVelocity.y, dragVec.y);
    _angularVelocity.z = Math::ApplyDrag(_angularVelocity.z, dragVec.z);
}
