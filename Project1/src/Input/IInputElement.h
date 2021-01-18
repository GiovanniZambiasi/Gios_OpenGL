#pragma once
#include <string>

namespace Gio::Input
{
    class IInputElement
    {
    public:
        virtual std::string GetName() = 0;

        virtual float GetValue() = 0;
        
        virtual void Update() = 0;
    };
}