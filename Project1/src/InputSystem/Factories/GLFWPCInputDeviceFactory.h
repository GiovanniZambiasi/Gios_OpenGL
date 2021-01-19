#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../IInputDeviceFactory.h"

namespace Gio::InputSystem::Factories
{
    class GLFWPCInputDeviceFactory : public IInputDeviceFactory
    {
    private:
        GLFWwindow* _window;
    public:
        GLFWPCInputDeviceFactory(GLFWwindow* window);
        
        ~GLFWPCInputDeviceFactory();
        
        void CreateDevices(std::vector<Gio::InputSystem::IInputDevice*>& collection) override;
    };
}
