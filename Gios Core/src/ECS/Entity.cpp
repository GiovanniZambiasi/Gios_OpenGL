#include "Entity.h"
#include "Component.h"
#include "IEntitySpawnHandler.h"
#include "../Debug.h"

Gio::ECS::IEntitySpawnHandler* Gio::ECS::Entity::spawnHandler = nullptr;

void Gio::ECS::Entity::RegisterSpawnHandler(IEntitySpawnHandler* handler)
{
    spawnHandler = handler;
}

Gio::ECS::Entity::Entity(std::string name)
    : _name(name)
    , _transform(Transform())
    , _components(std::vector<Component*>())
{
    if(spawnHandler!= nullptr)
    {
        spawnHandler->HandleEntitySpawned(*this);
    }
    else
    {
        Debug::LogError("Entity '" + _name + "' was spawned without an active spawn handler!");
    }
}

Gio::ECS::Entity::~Entity()
{
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
    
    OnUpdate(deltaTime);
}

void Gio::ECS::Entity::Draw(Renderer& renderer)
{
    for (unsigned int i = 0; i < _components.size(); i++)
    {
        auto component = _components[i];
        component->Draw(renderer);
    }
    
    OnDraw(renderer);
}

void Gio::ECS::Entity::Delete()
{
    _isDeleted = true;
}
