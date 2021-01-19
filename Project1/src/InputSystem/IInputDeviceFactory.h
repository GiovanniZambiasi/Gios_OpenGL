#pragma once
#include <vector>

#include "IInputDevice.h"

namespace Gio::InputSystem
{
    class IInputDeviceFactory
    {
    public:
        virtual void CreateDevices(std::vector<Gio::InputSystem::IInputDevice*>& collection) = 0;
    };
}