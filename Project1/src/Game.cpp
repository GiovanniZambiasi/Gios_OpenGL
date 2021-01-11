#include "Game.h"

#include "Camera.h"
#include "Debug.h"
#include "Math.h"
#include "Renderer.h"
#include "ECS/ObjectRenderer.h"

Gio::Game::Game()
{
    ECS::Entity* cube = new ECS::Entity();

    float vertices[] =
    {
        100.0f, 100.0f,
        200.0f, 100.0f,
        200.0f, 200.0f,
        100.0f, 200.0f,
    };

    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    auto renderer = new ECS::ObjectRenderer(cube, vertices, 4 * 2 * sizeof(float), indices, 6,
                                            Color(0.0f, 0.7f, 0.3f, 1.0f));

    cube->AddComponent(renderer);
    cube->GetTransform().Rotate(Vector3::Forward() * 45);
    cube->GetTransform().Translate(Vector3::Right() * .2f);

    AddEntity(cube);

    float vertices2[] =
    {
        200.0f, 200.0f,
        300.0f, 200.0f,
        300.0f, 300.0f,
        200.0f, 300.0f,
    };

    ECS::Entity* cube2 = new ECS::Entity();
    auto renderer2 = new ECS::ObjectRenderer(cube, vertices2, 4 * 2 * sizeof(float), indices, 6,
                                             Color(.9f, 0.1f, 0.0f, 1.0f));
    cube2->AddComponent(renderer2);

    AddEntity(cube2);
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
            return;
        }
    }
}

void Gio::Game::Update(float deltaTime)
{
    for (int i = _entities.size() - 1; i >= 0; i--)
        // Loops in reverse because a component's update could result in the object being destroyed
    {
        auto entity = _entities[i];

        entity->Update(deltaTime);

        Transform& trans = entity->GetTransform();

        trans.Translate(Vector3::Up() * 10.0f * deltaTime);
        
        /*
        entity->GetTransform().Rotate(Vector3::Forward() * (10.0f * deltaTime));

        auto up = entity->GetTransform().GetUp();
        */
        
        //Debug::Log("Entity's up: " + up.to_string() + " rotation: " + entity->GetTransform().rotation.to_string());
    }

    //Camera::GetTransform().Translate(Vector3::Right() * deltaTime * 10.0f);
}

void Gio::Game::Draw()
{
    for (int i = _entities.size() - 1; i >= 0; i--)
        // Loops in reverse because a component's update could result in the object being destroyed
    {
        auto entity = _entities[i];

        entity->Draw();
    }
}
