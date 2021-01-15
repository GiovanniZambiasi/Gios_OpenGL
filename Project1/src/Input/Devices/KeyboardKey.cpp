#include "KeyboardKey.h"

Gio::Input::Devices::KeyboardKey::KeyboardKey(std::string name, Types type, int glfwKeyID, GLFWwindow* window)
    : _type(type)
    , _name(name)
    , _glfwKeyID(glfwKeyID)
    , _window(window)
    , _isPressed(false)
    , _wasPressedThisFrame(false)
{
}

Gio::Input::Devices::KeyboardKey::~KeyboardKey()
{}

void Gio::Input::Devices::KeyboardKey::Update()
{
    bool wasPressed = _isPressed;
    
    _isPressed = glfwGetKey(_window, _glfwKeyID);

    _wasPressedThisFrame = _isPressed && !wasPressed;
    _wasReleasedThisFrame = wasPressed && !_isPressed;
}