﻿#pragma once

#include <vector>

#include "../Renderer.h"
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

        virtual ~Entity();

        std::string GetName() { return _name; }
        
        Transform& GetTransform() { return _transform; }

        bool IsDeleted() { return _isDeleted; }

        void AddComponent(Component* component);

        void RemoveComponent(Component* component);

        template<typename TComponent>
        TComponent* GetComponent();
        
        void Update(float deltaTime);

        virtual void OnUpdate(float deltaTime) {}
        
        void Draw(Renderer& renderer);

        void Delete();
    };

    template <typename TComponent>
    TComponent* Entity::GetComponent()
    {
        for (int i = 0; i < _components.size(); i++)
        {
            Component* device = _components[i];

            TComponent* ptr = dynamic_cast<TComponent*>(device);

            if (ptr != nullptr)
                return ptr;
        }

        return nullptr;
    }
}
