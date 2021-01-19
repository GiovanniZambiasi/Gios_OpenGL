#pragma once
#include <string>
#include <vector>

#include "DeviceElementPair.h"
namespace Gio::Input
{
    struct InputActionBinding
    {
        std::string actionName;
        std::vector<DeviceElementPair> elements;

        InputActionBinding(const std::string& actionName, const std::vector<DeviceElementPair>& elements)
            : actionName(actionName),
              elements(elements)
        {
        }
    };
}