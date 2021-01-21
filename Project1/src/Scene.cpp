#include "Scene.h"
#include "Debug.h"
#include "Renderer.h"
#include "ECS/Entity.h"
#include "ECS/Components/ObjectRenderer.h"
#include "ECS/Entities/MovingRotatingSquare.h"
#include "ECS/Entities/SpaceShip.h"
#include "Utilities/StdVectorUtilities.h"

Gio::Scene::Scene()
{
    ECS::Entity::RegisterSpawnHandler(this);
    
    for (auto i = 0; i < 1000; i++)
    {
        auto position = Vector3(Random::Between(-2000.0f, 2000.0f), Random::Between(-2000.0f, 2000.0f), 0.0f);
        new ECS::Entities::Star(Color::White(), position);    
    }

    new ECS::Entities::SpaceShip();
    //new ECS::Entities::MovingRotatingSquare(Color::Red(), Vector3(.0f, 0.0f, 0.0f), 10.0f);
}

Gio::Scene::~Scene()
{
}

void Gio::Scene::HandleEntitySpawned(ECS::Entity& entity)
{
    AddEntity(&entity);
}

void Gio::Scene::AddEntity(ECS::Entity* entity)
{
    if(Utilities::Contains(entity, _entities))
        return;
    
    _entities.push_back(entity);
}

void Gio::Scene::RemoveEntity(ECS::Entity* entity)
{
    for (int i = 0; i < _entities.size(); i++)
    {
        auto currEntity = _entities[i];

        if (currEntity == entity)
        {
            _entities.erase(_entities.begin() + i);
            break;
        }
    }

    delete entity;
}

void Gio::Scene::Update(float deltaTime)
{    
    for (int i = _entities.size() - 1; i >= 0; i--)        // Loops in reverse because entities can get destroyed and removed from the collection
    {
        auto entity = _entities[i];
            
        if(entity->IsDeleted())
        {
            RemoveEntity(entity);
        }
        else
        {
            entity->Update(deltaTime);
        }
    }
}

void Gio::Scene::Draw(Renderer& renderer)
{
    for (int i = 0; i < _entities.size(); i++)
    {
        auto entity = _entities[i];

        entity->Draw(renderer);
    }
}
