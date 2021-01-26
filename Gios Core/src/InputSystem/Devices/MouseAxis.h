#pragma once
#include "../IInputElement.h"

namespace Gio::InputSystem::Devices
{
    class MouseAxis : public IInputElement
    {
    private:
        static const float sensitivity;
        
        std::string _name;
        float _previous;
        float _axisValue;
    
    public:
        MouseAxis(std::string name);

        ~MouseAxis();

        std::string GetName() override { return _name; }
        
        float GetValue() override { return _axisValue; }
        
        void Update() override;

        void Update(float position);
    };
}
