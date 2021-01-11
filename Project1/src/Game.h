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

        void AddEntity(ECS::Entity* entity);
        
        void RemoveEntity(ECS::Entity* entity);
        
        void Update(float deltaTime);
        
        void Draw();
    };
}
