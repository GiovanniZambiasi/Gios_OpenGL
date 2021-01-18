#include "MouseButton.h"

Gio::Input::Devices::MouseButton::MouseButton(GLFWwindow* window, unsigned int id)
    : _window(window)
    , _id(id)
    , _name("Mouse Button " + std::to_string(_id))
    , _isPressed(false)
    , _wasPressedThisFrame(false)
    , _wasReleasedThisFrame(false)
{
}

Gio::Input::Devices::MouseButton::~MouseButton()
{
}

void Gio::Input::Devices::MouseButton::Update()
{
    bool wasPressed = _isPressed;
    
    _isPressed = glfwGetMouseButton(_window, _id);
    
    _wasPressedThisFrame = _isPressed && !wasPressed;
    _wasReleasedThisFrame = wasPressed && !_isPressed;
}
