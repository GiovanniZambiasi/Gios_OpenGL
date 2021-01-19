#include "MouseButton.h"

Gio::InputSystem::Devices::MouseButton::MouseButton(GLFWwindow* window, unsigned int id)
    : _window(window)
    , _id(id)
    , _name("Mouse Button " + std::to_string(_id))
    , _value(0.0f)
{
}

Gio::InputSystem::Devices::MouseButton::~MouseButton()
{
}

void Gio::InputSystem::Devices::MouseButton::Update()
{
    bool isPressed = glfwGetMouseButton(_window, _id);

    _value = isPressed ? 1.0f : 0.0f;
}
