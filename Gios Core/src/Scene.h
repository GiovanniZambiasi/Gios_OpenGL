#pragma once
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
        std::string _name;
    
    public:
        Scene();
        
        ~Scene();

        std::vector<ECS::Entity*>& GetEntities() { return _entities; }

        void HandleEntitySpawned(ECS::Entity& entity) override;
        
        void AddEntity(ECS::Entity* entity);
        
        void RemoveEntity(ECS::Entity* entity);
        
        void Update(float deltaTime);
        
        void Draw(Renderer& renderer);

        ECS::Entity* GetEntity(const std::string& name);

        template <typename TEntity>
        TEntity* GetEntity();
    };

    template <typename TEntity>
    TEntity* Scene::GetEntity()
    {
        for (int i = 0; i < _entities.size(); i++)
        {
            auto entity = dynamic_cast<TEntity*>(_entities[i]);
        
            if(entity != nullptr)
                return entity;
        }

        return nullptr;
    }
}
