#pragma once
#include "MouseButton.h"
#include "../IInputDevice.h"

namespace Gio::Input::Devices
{
    class Mouse : public IInputDevice
    {
    private:
        std::vector<MouseButton*> _buttons;
        GLFWwindow* _window;
        
    public:
        Mouse(GLFWwindow* window);

        ~Mouse();
        
        std::string GetName() { return "Mouse"; }
        
        void Update() override;
        
        void GetElements(std::vector<IInputElement*>& elements) override;
    };
}