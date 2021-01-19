#include "Mouse.h"

const unsigned int GLFWTotalMouseButtonCount = 8;

Gio::InputSystem::Devices::Mouse::Mouse(GLFWwindow* window)
    : _window(window)
{
    for (unsigned int i = 0; i < GLFWTotalMouseButtonCount; i++)
    {
        auto button = new MouseButton(window, i);
        elements.push_back(button);
    }
}

Gio::InputSystem::Devices::Mouse::~Mouse()
{
}