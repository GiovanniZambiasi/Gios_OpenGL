#pragma once
#include "Device.h"
#include "MouseAxis.h"
#include "MouseButton.h"
#include "../../Vector2.h"

namespace Gio::InputSystem::Devices
{
    class Mouse : public Device
    {
    private:
        GLFWwindow* _window;
        MouseAxis* _horizontal;
        MouseAxis* _vertical;
        Vector2 _position;
        
    public:
        Mouse(GLFWwindow* window);

        ~Mouse();

        void Update() override;
        
        std::string GetName() { return "Mouse"; }

        Vector2 GetCursorPosition() { return _position; }
    
    private:
        void RecordCursorPosition();
        
    };
}
