#include "GLFWKeyboardKeyData.h"

void Gio::InputSystem::Devices::to_json(nlohmann::json& j, const GLFWKeyboardKeyData& keyData)
{
    j = nlohmann::json{
        {"name", keyData.name},
        {"KeyboardKeyType", keyData.type},
        {"glfwKeyID", keyData.glfwKeyID},
    };
}

void Gio::InputSystem::Devices::from_json(const nlohmann::json& j, GLFWKeyboardKeyData& keyData)
{
    j.at("name").get_to(keyData.name);
    j.at("KeyboardKeyType").get_to(keyData.type);
    j.at("glfwKeyID").get_to(keyData.glfwKeyID);
}
