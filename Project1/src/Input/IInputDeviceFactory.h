#pragma once
#include <vector>

#include "IInputDevice.h"

namespace Gio::Input
{
    class IInputDeviceFactory
    {
    public:
        virtual void CreateDevices(std::vector<Gio::Input::IInputDevice*>& collection) = 0;
    };
}