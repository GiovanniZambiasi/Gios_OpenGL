#pragma once
#include <string>
#include <vector>

#include "DeviceElementPair.h"

namespace Gio::Input
{
    struct InputAxisBindings
    {
        std::string axisName;
        std::vector<DeviceElementPair> positiveContributors;
        std::vector<DeviceElementPair> negativeContributors;
    };
}