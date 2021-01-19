#pragma once

#include <json.hpp>
#include <string>
#include "KeyboardKey.h"

namespace Gio::InputSystem::Devices
{
    struct GLFWKeyboardKeyData
    {
    public:
        GLFWKeyboardKeyData(const std::string& name, KeyboardKey::Types type, int glfwKeyID)
            : name(name),
              type(type),
              glfwKeyID(glfwKeyID)
        { }

        GLFWKeyboardKeyData()
            :name("NULL")
            ,type(KeyboardKey::Unknown)
            ,glfwKeyID(0)
        { }
        
        std::string name;
        KeyboardKey::Types type;
        int glfwKeyID;
        
        std::string to_string() const { return name + " Gio's Type ID: " + std::to_string(type) + " GLFW Type ID: " + std::to_string(glfwKeyID); }
    };

    void to_json(nlohmann::json& j, const GLFWKeyboardKeyData& keyData);

    void from_json(const nlohmann::json& j, GLFWKeyboardKeyData& keyData);
}