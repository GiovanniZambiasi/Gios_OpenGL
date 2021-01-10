#include "Entity.h"
#include "Component.h"

Gio::ECS::Entity::Entity()
    : _transform(Transform())
    , _components(std::vector<Component*>())
{ }

Gio::ECS::Entity::~Entity()
{ }

void Gio::ECS::Entity::AddComponent(Component* component)
{
    _components.push_back(component);
}

void Gio::ECS::Entity::RemoveComponent(Component* component)
{
    for (unsigned int i =0; i < _components.size(); i++)
    {
        auto comp = _components.at(i);

        if(comp == component)
        {
            _components.erase(_components.begin() + i);

            delete component;
            return;
        }
    }
}

void Gio::ECS::Entity::Update(float deltaTime)
{
    for (unsigned int i = 0; i < _components.size(); i++)
    {
        auto component = _components[i];
        component->Update(deltaTime);
    }
}

void Gio::ECS::Entity::LateUpdate(float deltaTime)
{
    for (unsigned int i = 0; i < _components.size(); i++)
    {
        auto component = _components[i];
        component->LateUpdate(deltaTime);
    }
}
