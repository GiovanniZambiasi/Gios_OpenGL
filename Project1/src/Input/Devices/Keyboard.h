#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "KeyboardKey.h"
#include "../IInputDevice.h"

namespace Gio::Input::Devices
{
    class Keyboard : public IInputDevice
    {
    private:
        std::vector<KeyboardKey*> _keys;
    
    public:
        Keyboard(GLFWwindow* window);
        
        ~Keyboard();
        
        std::string GetName() override { return "Keyboard"; }
        
        void Update() override;
        
        void GetElements(std::vector<IInputElement*>& elements) override;

        KeyboardKey* GetKey(KeyboardKey::Types type);
    };
}
