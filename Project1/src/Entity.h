#pragma once

#include <vector>
#include "Transform.h"
#include "ECS/Component.h"

namespace Gio
{   
    class Entity sealed
    {
    private:
        Transform* _transform;
        std::vector<ECS::Component*>* _components;
    
    public:
        Entity();

        ~Entity();

        Transform* GetTransform() { return _transform; }

        void AddComponent(ECS::Component* component);

        void RemoveComponent(ECS::Component* component);
        
        void Update(float deltaTime);

        void LateUpdate(float deltaTime);
    };
}
