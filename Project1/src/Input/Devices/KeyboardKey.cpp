#include "KeyboardKey.h"

Gio::Input::Devices::KeyboardKey::KeyboardKey(std::string name, Types type, int glfwKeyID, GLFWwindow* window)
    : _type(type)
    , _name(name)
    , _glfwKeyID(glfwKeyID)
    , _window(window)
    , _value(0.0f)
{
}

Gio::Input::Devices::KeyboardKey::~KeyboardKey()
{}

void Gio::Input::Devices::KeyboardKey::Update()
{
    bool isPressed = glfwGetKey(_window, _glfwKeyID);

    _value = isPressed ? 1.0f : 0.0f;
}