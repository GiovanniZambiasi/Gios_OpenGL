#pragma once
#include <string>

#include "json.hpp"

namespace Gio::InputSystem
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

        DeviceElementPair()
        {
        }

        ~DeviceElementPair()
        {
        }
    };

    inline void to_json(nlohmann::json& j, const DeviceElementPair& pair)
    {
        j = nlohmann::json{
            {"Device", pair.device},
            {"Element", pair.element},
            };
    }

    inline void from_json(const nlohmann::json& j, DeviceElementPair& pair)
    {
        j.at("Device").get_to(pair.device);
        j.at("Element").get_to(pair.element);
    }
}
