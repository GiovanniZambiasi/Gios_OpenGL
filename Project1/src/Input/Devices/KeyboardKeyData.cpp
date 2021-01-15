#include "KeyboardKeyData.h"

void Gio::Input::Devices::to_json(nlohmann::json& j, const Gio::Input::Devices::KeyboardKeyData& keyData)
{
    j = nlohmann::json{
        {"name", keyData.name},
        {"KeyboardKeyType", keyData.type},
        {"glfwKeyID", keyData.glfwKeyID},
    };
}

void Gio::Input::Devices::from_json(const nlohmann::json& j, Gio::Input::Devices::KeyboardKeyData& keyData)
{
    j.at("name").get_to(keyData.name);
    j.at("KeyboardKeyType").get_to(keyData.type);
    j.at("glfwKeyID").get_to(keyData.glfwKeyID);
}
