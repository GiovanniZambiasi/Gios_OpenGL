#include "Component.h"

Gio::ECS::Component::Component(Entity& entity)
    : entity(entity)
{
}

Gio::ECS::Component::~Component()
{
}