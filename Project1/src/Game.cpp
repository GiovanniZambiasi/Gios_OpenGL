#include "Game.h"
#include "Camera.h"
#include "Debug.h"
#include "Math.h"
#include "Renderer.h"
#include "time.h"
#include "ECS/Components/ObjectRenderer.h"

Gio::Game::Game()
{
    instance = this;
    
    ECS::Entity* cube = new ECS::Entity("Green Cube");

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

    auto renderer = new ECS::Components::ObjectRenderer(*cube, vertices, 4 * 2 * sizeof(float), indices, 6,
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
            break;
        }
    }

    delete entity;
}

void Gio::Game::Update(float deltaTime)
{
    float time = Time::GetTimeSinceStartSeconds();
    float sinOfTime =Math::Sin(time * 100.0f); 
    float sinAnim = sinOfTime * 150.0f;

    for (int i = _entities.size() - 1; i >= 0; i--)        // Loops in reverse because entities can get destroyed, and removed from the collection
    {
        auto entity = _entities[i];
            
        if(entity->IsDeleted())
        {
            RemoveEntity(entity);
        }
        else
        {
            entity->Update(deltaTime);

            Transform& trans = entity->GetTransform();

            //auto scale = trans.GetScale();
            //scale.y = 100.0f * scaleAnim;

            //trans.SetScale(scale);
        
            trans.position = Vector3::Up() * sinAnim;

            //entity->GetTransform().Rotate(Vector3::Forward() * (720.0f * deltaTime));
        
            //Debug::Log("Entity's up: " + up.to_string() + " rotation: " + entity->GetTransform().rotation.to_string());
        }
    }
}

void Gio::Game::Draw()
{
    for (int i = 0; i < _entities.size(); i++)
    {
        auto entity = _entities[i];

        entity->Draw();
    }
}
