#pragma once
#include <string>
#include <vector>

#include "../DeviceElementPair.h"

namespace Gio::InputSystem::Actions
{
    struct InputAxisBindings
    {
        std::string axisName;
        std::vector<DeviceElementPair> positiveContributors;
        std::vector<DeviceElementPair> negativeContributors;

        InputAxisBindings()
        {}

        ~InputAxisBindings(){}
    };

    inline void to_json(nlohmann::json& j, const InputAxisBindings& binding)
    {
        j = nlohmann::json();
        j["Axis Name"] = binding.axisName;
        j["+"] = binding.positiveContributors;
        j["-"] = binding.negativeContributors;
    }

    inline void from_json(const nlohmann::json& j, InputAxisBindings& binding)
    {
        j.at("Axis Name").get_to(binding.axisName);
        j.at("+").get_to(binding.positiveContributors);
        j.at("-").get_to(binding.negativeContributors);
    }
}
