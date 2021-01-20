#pragma once

namespace Gio::ECS
{
    class Entity;

    class IEntitySpawnHandler
    {
    public:
        virtual void HandleEntitySpawned(Entity& entity) = 0;
    };
}
