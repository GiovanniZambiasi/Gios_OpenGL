#include "Game.h"

#include "Camera.h"
#include "Debug.h"
#include "Math.h"
#include "Renderer.h"
#include "time.h"
#include "ECS/ObjectRenderer.h"

Gio::Game::Game()
{
    ECS::Entity* cube = new ECS::Entity();

    float vertices[] =
    {
        -1.0f, -1.0f,
        -1.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, -1.0f,
    };

    unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    auto renderer = new ECS::ObjectRenderer(cube, vertices, 4 * 2 * sizeof(float), indices, 6,
                                            Color(0.0f, 0.7f, 0.3f, 1.0f));

    cube->AddComponent(renderer);

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
            return;
        }
    }
}

void Gio::Game::Update(float deltaTime)
{
    float scaleAnim = Math::Sin(Time::GetTimeSinceStartSeconds() * 100.0f);
    
    for (int i = _entities.size() - 1; i >= 0; i--)
        // Loops in reverse because a component's update could result in the object being destroyed
    {
        auto entity = _entities[i];

        entity->Update(deltaTime);

        Transform& trans = entity->GetTransform();

        auto scale = trans.GetScale();
        scale.y = 100.0f * scaleAnim;

        //trans.SetScale(scale);
        
        //trans.Translate(Vector3::Up() * 10.0f * deltaTime);
        
        entity->GetTransform().Rotate(Vector3::Forward() * (180.0f * deltaTime));
        
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
