#pragma once
#include <GLFW/glfw3.h>

#include "../IInputElement.h"

namespace Gio::Input::Devices
{
    class MouseButton : public IInputElement
    {
    private:
        GLFWwindow* _window;
        unsigned int _id;
        std::string _name;
        bool _isPressed;
        bool _wasPressedThisFrame;
        bool _wasReleasedThisFrame;

    public:
        MouseButton(GLFWwindow* window, unsigned int id);

        ~MouseButton();
        
        std::string GetName() { return _name; }
        
        bool IsPressed() override { return _isPressed; }
        
        bool WasPressedThisFrame() override { return _wasPressedThisFrame; }
        
        bool WasReleasedThisFrame() override { return _wasReleasedThisFrame; }
        
        void Update() override;
    };
}
