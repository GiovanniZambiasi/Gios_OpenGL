#pragma once

#include <string>
#include <vector>
#include "IInputElement.h"

namespace Gio::InputSystem
{
    class IInputDevice
    {
    public:
        virtual std::string GetName() = 0;
        
        virtual void Update() = 0;

        virtual void GetElements(std::vector<IInputElement*>& elements) = 0;

        virtual IInputElement* GetElement(const std::string& name) = 0;
    };
}
