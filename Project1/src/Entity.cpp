#include "Entity.h"
#include "ECS/Component.h"

Gio::Entity::Entity()
{
    _components = new std::vector<ECS::Component*>();

    _transform = new Transform();
}

Gio::Entity::~Entity()
{
}

void Gio::Entity::AddComponent(ECS::Component* component)
{
    _components->push_back(component);
}

void Gio::Entity::RemoveComponent(ECS::Component* component)
{
    for (int i =0; i < _components->size(); i++)
    {
        auto comp = _components->at(i);

        if(comp == component)
        {
            _components->erase(_components->begin() + i);
            return;
        }
    }
}

void Gio::Entity::Update(float deltaTime)
{
    auto components = *_components;
    for (int i = 0; i < components.size(); i++)
    {
        auto component = components[i];
        component->Update(deltaTime);
    }
}

void Gio::Entity::LateUpdate(float deltaTime)
{
    auto components = *_components;
    for (int i = 0; i < components.size(); i++)
    {
        auto component = components[i];
        component->LateUpdate(deltaTime);
    }
}
