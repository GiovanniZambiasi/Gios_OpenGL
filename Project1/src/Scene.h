﻿#pragma once
#include <vector>
#include "Renderer.h"
#include "ECS/Entity.h"
#include "ECS/IEntitySpawnHandler.h"

namespace Gio
{
    class Scene : public ECS::IEntitySpawnHandler
    {
    private:
        std::vector<ECS::Entity*> _entities;

    public:
        Scene();
        
        ~Scene();

        std::vector<ECS::Entity*>& GetEntities() { return _entities; }

        void HandleEntitySpawned(ECS::Entity& entity) override;
        
        void AddEntity(ECS::Entity* entity);
        
        void RemoveEntity(ECS::Entity* entity);
        
        void Update(float deltaTime);
        
        void Draw(Renderer& renderer);
    };
}
