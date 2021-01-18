#include "MouseButton.h"

Gio::Input::Devices::MouseButton::MouseButton(GLFWwindow* window, unsigned int id)
    : _window(window)
    , _id(id)
    , _name("Mouse Button " + std::to_string(_id))
    , _value(0.0f)
{
}

Gio::Input::Devices::MouseButton::~MouseButton()
{
}

void Gio::Input::Devices::MouseButton::Update()
{
    bool isPressed = glfwGetMouseButton(_window, _id);

    _value = isPressed ? 1.0f : 0.0f;
}
