#pragma once
#include "../ECS/Entity.h"

namespace Gio::Example
{
    class Projectile : public ECS::Entity
    {
    private:
        float _lifespan;
    
    public:

        Projectile(Vector3 position, Vector3 rotation, Vector3 initialVelocity);

        ~Projectile();

        void OnUpdate(float deltaTime) override;
        
    };
}
