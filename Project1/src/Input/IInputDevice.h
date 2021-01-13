#pragma once

#include <string>
#include <vector>
#include "IInputElement.h"

namespace Gio::Input
{
    class IInputDevice
    {
    public:
        virtual std::string GetName() = 0;
        
        virtual void Update() = 0;

        virtual void GetElements(std::vector<IInputElement*>& elements) = 0;
    };
}
