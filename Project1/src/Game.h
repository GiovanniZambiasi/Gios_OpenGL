#pragma once
#include <vector>

#include "ECS/Entity.h"

namespace Gio
{
    class Game
    {
    private:
        std::vector<ECS::Entity*> _entities;

    public:
        Game();
        
        ~Game();

        std::vector<ECS::Entity*>& GetEntities() { return _entities; }
        
        void AddEntity(ECS::Entity* entity);
        
        void RemoveEntity(ECS::Entity* entity);
        
        void Update(float deltaTime);
        
        void Draw();

        inline static Game* instance = nullptr;
    };
}
