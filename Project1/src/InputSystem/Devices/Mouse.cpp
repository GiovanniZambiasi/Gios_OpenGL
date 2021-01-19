#include "Mouse.h"

const unsigned int GLFWTotalMouseButtonCount = 8;

Gio::InputSystem::Devices::Mouse::Mouse(GLFWwindow* window)
    : _window(window)
    , _horizontal(new MouseAxis("Mouse Horizontal"))
    , _vertical(new MouseAxis("Mouse Vertical"))
{
    for (unsigned int i = 0; i < GLFWTotalMouseButtonCount; i++)
    {
        auto button = new MouseButton(window, i);
        elements.push_back(button);
    }

    elements.push_back(_horizontal);
    elements.push_back(_vertical);
}

Gio::InputSystem::Devices::Mouse::~Mouse()
{
    delete _horizontal;
    delete _vertical;
}

void Gio::InputSystem::Devices::Mouse::Update()
{
    Device::Update();

    RecordCursorPosition();
    
    _horizontal->Update(_position.x);
    
    _vertical->Update(_position.y);
}

void Gio::InputSystem::Devices::Mouse::RecordCursorPosition()
{
    auto posX = new double;
    auto posY = new double;
    
    glfwGetCursorPos(_window, posX, posY);

    _position = Vector2(*posX, *posY);
    
    delete posX;
    delete posY;
}
