#pragma once

#include <vector>
#include "../Transform.h"

namespace Gio::ECS
{
    class Component;

    class Entity
    {
    private:
        std::string _name;
        Transform _transform;
        std::vector<Component*> _components;
        bool _isDeleted = false;
        
    public:
        Entity(std::string name);

        ~Entity();

        std::string GetName() { return _name; }
        
        Transform& GetTransform() { return _transform; }

        bool IsDeleted() { return _isDeleted; }

        void AddComponent(Component* component);

        void RemoveComponent(Component* component);
        
        void Update(float deltaTime);

        void Draw();

        void Delete();
    };
}
