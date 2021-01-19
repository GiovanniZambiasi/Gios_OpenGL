﻿#include "Scene.h"
#include "Debug.h"
#include "Renderer.h"
#include "ECS/Components/ObjectRenderer.h"
#include "ECS/Entities/RotatingSquare.h"

Gio::Scene::Scene()
{
    ECS::Entities::RotatingSquare* square = new ECS::Entities::RotatingSquare(Color::Red(), Vector3(-200.0f, 0.0f, 0.0f));
    
    AddEntity(square);
    
    square = new ECS::Entities::RotatingSquare(Color::Blue(), Vector3(200.0f, 0.0f, 0.0f));

    AddEntity(square);
}

Gio::Scene::~Scene()
{
}

void Gio::Scene::AddEntity(ECS::Entity* entity)
{
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