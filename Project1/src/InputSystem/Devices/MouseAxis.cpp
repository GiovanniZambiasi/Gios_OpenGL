#include "MouseAxis.h"

Gio::InputSystem::Devices::MouseAxis::MouseAxis(std::string name)
    : _name(name)
    , _previous(0)
    , _axisValue(0)
{
}

Gio::InputSystem::Devices::MouseAxis::~MouseAxis()
{
}

void Gio::InputSystem::Devices::MouseAxis::Update()
{
}

void Gio::InputSystem::Devices::MouseAxis::Update(float position)
{
    float delta = position - _previous;

    _axisValue = delta;

    _previous = position;
}
