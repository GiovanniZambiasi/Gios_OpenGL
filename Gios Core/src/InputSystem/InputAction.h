#pragma once
#include <string>
#include <vector>

#include "IInputElement.h"

namespace Gio::InputSystem
{
    class InputAction
    {
    private:
        std::string _name;
        std::vector<IInputElement*> _elements;
        bool _isPressed;
        bool _wasPressedThisFrame;
        bool _wasReleasedThisFrame;
    
    public:
        InputAction(const std::string& name, std::vector<IInputElement*> elements);

        ~InputAction();
        
        std::string GetName() { return _name; }
        
        bool IsPressed() { return _isPressed; }
        
        bool WasPressedThisFrame() { return _wasPressedThisFrame; }
        
        bool WasReleasedThisFrame() { return _wasReleasedThisFrame; }

        void Update();

        void GetElements(std::vector<IInputElement*>& collection);
    
    private:
        bool AreAnyElementsPressed();
    };
}
