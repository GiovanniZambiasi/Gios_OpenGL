﻿#include "Rotator.h"

void Gio::ECS::Components::Rotator::Update(float deltaTime)
{
    Transform& trans = entity.GetTransform();

    trans.Rotate(Vector3::Forward() * (_rotationSpeed * deltaTime));
}