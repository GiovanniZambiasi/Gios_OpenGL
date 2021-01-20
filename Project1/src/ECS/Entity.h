#pragma once

#include <vector>

#include "IEntitySpawnHandler.h"
#include "../Renderer.h"
#include "../Transform.h"

namespace Gio::ECS
{
    class Component;

    class Entity
    {
    private:
        static IEntitySpawnHandler* spawnHandler;

    public:
        static void RegisterSpawnHandler(IEntitySpawnHandler* handler);
    
    private:
        std::string _name;
        Transform _transform;
        std::vector<Component*> _components;
        bool _isDeleted = false;
        
    public:
        Entity(std::string name);

        virtual ~Entity();

        std::string GetName() { return _name; }

        void SetName(const std::string& name) { _name = name; }
        
        Transform& GetTransform() { return _transform; }

        bool IsDeleted() { return _isDeleted; }

        void AddComponent(Component* component);

        void RemoveComponent(Component* component);

        template<typename TComponent>
        TComponent* GetComponent();
        
        void Update(float deltaTime);

        void Draw(Renderer& renderer);

        void Delete();

        virtual void OnUpdate(float deltaTime) {}

        virtual void OnDraw(Renderer& renderer) {}
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
