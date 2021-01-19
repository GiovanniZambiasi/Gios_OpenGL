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

        InputActionBinding()
        {
        }
    };

    inline void to_json(nlohmann::json& j, const InputActionBinding& binding)
    {
        j = nlohmann::json{
            {"Action Name", binding.actionName},
        };

        j["Elements"] = binding.elements;
    }

    inline void from_json(const nlohmann::json& j, InputActionBinding& binding)
    {
        j.at("Action Name").get_to(binding.actionName);
        j.at("Elements").get_to(binding.elements);
    }
}