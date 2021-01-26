#pragma once
#include <GLFW/glfw3.h>

#include "../IInputElement.h"

namespace Gio::InputSystem::Devices
{
    class MouseButton : public IInputElement
    {
    private:
        GLFWwindow* _window;
        unsigned int _id;
        std::string _name;
        float _value;
    
    public:
        MouseButton(GLFWwindow* window, unsigned int id);

        ~MouseButton();
        
        std::string GetName() { return _name; }
        
        float GetValue() override {return _value;}
        
        void Update() override;
    };
}
