#pragma once
#include "Device.h"
#include "MouseButton.h"
#include "../IInputDevice.h"

namespace Gio::Input::Devices
{
    class Mouse : public Device
    {
    private:
        GLFWwindow* _window;
        
    public:
        Mouse(GLFWwindow* window);

        ~Mouse();
        
        std::string GetName() { return "Mouse"; }
    };
}