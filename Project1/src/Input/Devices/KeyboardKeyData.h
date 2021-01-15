#pragma once

#include <json.hpp>
#include <string>
#include "KeyboardKey.h"

namespace Gio::Input::Devices
{
    struct KeyboardKeyData
    {
    public:
        KeyboardKeyData(const std::string& name, KeyboardKey::Types type, int glfw_key_id)
            : name(name),
              type(type),
              glfwKeyID(glfw_key_id)
        {
        }

        std::string name;
        KeyboardKey::Types type;
        int glfwKeyID;
    };

    void to_json(nlohmann::json& j, const Gio::Input::Devices::KeyboardKeyData& keyData);

    void from_json(const nlohmann::json& j, Gio::Input::Devices::KeyboardKeyData& keyData);
}
