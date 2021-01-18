#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Device.h"
#include "KeyboardKey.h"

namespace Gio::Input::Devices
{
    class Keyboard : public Device
    {
    public:
        Keyboard(GLFWwindow* window);
        
        ~Keyboard();
        
        std::string GetName() override { return "Keyboard"; }
        
        KeyboardKey* GetKey(KeyboardKey::Types type);
    };
}
