#include "Input.h"

void Gio::Input::Input::Initialize(Window& window)
{
    _window = &window;
}

bool Gio::Input::Input::GetKeyDown(Key key)
{
    int keyState = glfwGetKey(_window->GetGLFWWindow(), key);
    if(keyState == GLFW_PRESS)
        return true;
}
