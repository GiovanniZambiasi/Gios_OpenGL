#pragma once
#include "../Component.h"

namespace Gio::ECS::Components
{
    class Physics : public Component
    {
    private:
        Vector3 _velocity;
        Vector3 _angularVelocity;
        float _drag;
        float _angularDrag;
        float _mass;
    
    public:
        explicit Physics(Entity& entity, float mass, float drag, float angularDrag)
            : Component(entity)
            , _drag(drag)
            , _angularDrag(angularDrag)
            , _mass(mass)
        {
        }

        void Update(float deltaTime) override;

        void AddForce(Vector3 force);

        void AddTorque(Vector3 torque);

        Vector3 GetVelocity() { return _velocity; }
        
        Vector3 GetAngularVelocity() { return _angularVelocity; }

        void SetVelocity(Vector3 velocity) { _velocity = velocity; }
        
        void SetDrag(float drag) { _drag = drag; }

        void SetAngularDrag(float angularDrag) { _angularDrag = angularDrag; }
        
        void SetMass(float mass) { _mass = mass; }

    private:
        void ApplyDrag(float deltaTime);

        bool VelocityIsZero();
        
        void ApplyAngularDrag(float deltaTime);
    };
}
