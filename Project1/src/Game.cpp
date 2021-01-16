#include "Game.h"
#include "Debug.h"
#include "Renderer.h"
#include "ECS/Components/ObjectRenderer.h"
#include "ECS/Components/Rotator.h"
#include "Rendering/Primitives/Square.h"

Gio::Game::Game()
{
    ECS::Entity* cube = new ECS::Entity("Green Cube");

    auto mesh = new Rendering::Primitives::Square(1.0f, 1.0f);
    
    auto renderer = new ECS::Components::ObjectRenderer(*cube, *mesh, Color(0.0f, 0.4f, 0.0f, 1.0f));
    auto rotator = new ECS::Components::Rotator(*cube);

    cube->AddComponent(renderer);
    cube->AddComponent(rotator);

    Transform& cubeTransform = cube->GetTransform();
    cubeTransform.SetScale(Vector3::One() * 100.0f);
    
    AddEntity(cube);
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

        if (currEntity == entity)
        {
            _entities.erase(_entities.begin() + i);
            break;
        }
    }

    delete entity;
}

void Gio::Game::Update(float deltaTime)
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

void Gio::Game::Draw(Renderer& renderer)
{
    for (int i = 0; i < _entities.size(); i++)
    {
        auto entity = _entities[i];

        entity->Draw(renderer);
    }
}
