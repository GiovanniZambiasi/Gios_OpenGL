#pragma once
#include <string>
#include <vector>

#include "DeviceElementPair.h"

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