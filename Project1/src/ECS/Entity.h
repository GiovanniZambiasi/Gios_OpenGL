#pragma once

#include <vector>
#include "Transform.h"

namespace Gio::ECS
{
    class Component;

    class Entity sealed
    {
    private:
        Transform _transform;
        std::vector<Component*> _components;
    
    public:
        Entity();

        ~Entity();

        Transform* GetTransform() { return &_transform; }

        void AddComponent(Component* component);

        void RemoveComponent(Component* component);
        
        void Update(float deltaTime);

        void LateUpdate(float deltaTime);
    };
}
