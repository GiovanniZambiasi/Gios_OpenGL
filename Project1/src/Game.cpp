#include "Game.h"

#include "Debug.h"
#include "Math.h"
#include "Renderer.h"
#include "ECS/ObjectRenderer.h"

Gio::Game::Game()
{
    ECS::Entity* square = new ECS::Entity();

    std::vector<Vector2> vec = std::vector<Vector2>
    {
        Vector2(.0f, 1.0f),
        Vector2(-.5f, -.5f),
        Vector2(.5f, -.5f),
        /*Vector2(.5f, .5f),
        Vector2(.5f, -.5f),
        Vector2(-.5f, -.5f),*/
    };

    auto renderer = new ECS::ObjectRenderer(square, vec, Color(0.0f, 0.7f, 0.3f, 1.0f));

    square->AddComponent(renderer);

    square->GetTransform()->Rotate(Vector3::Forward() * (45.0f));
    
    AddEntity(square);
}

Gio::Game::~Game()
{
}

void Gio::Game::AddEntity(ECS::Entity* entity)
{
    _entities.push_back(entity);
}

void Gio::Game::RemoveEntity(ECS::Entity* entity)
{
    for (int i = 0; i < _entities.size(); i++)
    {
        auto currEntity = _entities[i];

        if(currEntity == entity)
        {
            _entities.erase(_entities.begin() + i);
            return;
        }
    }
}

void Gio::Game::RunUpdate(float deltaTime)
{
    for (int i = _entities.size() - 1; i >= 0; i--)
        // Loops in reverse because a component's update could result in the object being destroyed
    {
        auto entity = _entities[i];

        entity->Update(deltaTime);

        entity->GetTransform()->Rotate(Vector3::Forward() * (10.0f * deltaTime));

        auto up = entity->GetTransform()->GetUp();
        
        Debug::Log(entity->GetTransform()->rotation.to_string() + " | up: " + up.to_string() + " : Mag: " + std::to_string(up.GetMagnitude()));
    }
}

void Gio::Game::RunLateUpdate(float deltaTime)
{
    for (int i = _entities.size() - 1; i >= 0; i--)
        // Loops in reverse because a component's update could result in the object being destroyed
    {
        auto entity = _entities[i];

        entity->LateUpdate(deltaTime);
    }
}

void Gio::Game::Update(float deltaTime)
{
    RunUpdate(deltaTime);

    RunLateUpdate(deltaTime);
}
