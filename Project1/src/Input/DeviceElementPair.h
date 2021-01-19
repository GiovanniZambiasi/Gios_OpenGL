#pragma once
#include <string>

namespace Gio::Input
{
    struct DeviceElementPair
    {
        std::string device;
        std::string element;
    
        DeviceElementPair(const std::string& device, const std::string& element)
            : device(device)
            , element(element)
        {
        }
    };
}