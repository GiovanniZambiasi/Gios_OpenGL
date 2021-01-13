#include "Entity.h"
#include "Component.h"
#include "../Debug.h"

Gio::ECS::Entity::Entity(std::string name)
    : _name(name)
    , _transform(Transform())
    , _components(std::vector<Component*>())
{ }

Gio::ECS::Entity::~Entity()
{
    Gio::Debug::Log("Destroying " + _name);

    for (int i = _components.size() - 1; i >= 0; i--)
    {
        Component* component = _components[i];
        
        delete component;
    }
}

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

void Gio::ECS::Entity::Draw(Renderer& renderer)
{
    for (unsigned int i = 0; i < _components.size(); i++)
    {
        auto component = _components[i];
        component->Draw(renderer);
    }
}

void Gio::ECS::Entity::Delete()
{
    _isDeleted = true;
}
