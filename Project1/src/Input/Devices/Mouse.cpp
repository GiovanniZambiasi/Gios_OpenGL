#include "Mouse.h"

const unsigned int GLFWTotalMouseButtonCount = 8;

Gio::Input::Devices::Mouse::Mouse(GLFWwindow* window)
    : _window(window)
{
    for (unsigned int i = 0; i < GLFWTotalMouseButtonCount; i++)
    {
        auto button = new MouseButton(window, i);
        _buttons.push_back(button);
    }
}

Gio::Input::Devices::Mouse::~Mouse()
{
    for (int i = 0; i < _buttons.size(); i++)
    {
        auto button = _buttons[i];
        delete button;
    }
}

void Gio::Input::Devices::Mouse::Update()
{
    for (int i = 0; i < _buttons.size(); i++)
    {
        auto button = _buttons[i];
        button->Update();
    }
}

void Gio::Input::Devices::Mouse::GetElements(std::vector<IInputElement*>& elements)
{
    for (int i = 0; i < _buttons.size(); i++)
    {
        auto button = _buttons[i];
        elements.push_back(button);
    }
}
