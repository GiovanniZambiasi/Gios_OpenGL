#include "Component.h"

Gio::ECS::Component::Component(Entity* entity)
{
    this->entity = entity;
}
