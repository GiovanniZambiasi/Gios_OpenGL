#pragma once
#include <string>

namespace Gio::Input
{
    class IInputElement
    {
    public:
        virtual std::string GetName() = 0;
        
        virtual bool IsPressed() = 0;
        
        virtual bool WasPressedThisFrame() = 0;
        
        virtual bool WasReleasedThisFrame() = 0;

        virtual void Update() = 0;
    };
}
