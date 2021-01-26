#pragma once

namespace Gio::ECS
{
    class Entity;

    class IEntitySpawnHandler
    {
    public:
        virtual ~IEntitySpawnHandler() = default;
        virtual void HandleEntitySpawned(Entity& entity) = 0;
    };
}
