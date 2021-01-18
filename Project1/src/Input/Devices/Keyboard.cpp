#include "Keyboard.h"
#include "json.hpp"
#include "KeyboardKeyData.h"
#include <fstream>
#include "../../Debug.h"

Gio::Input::Devices::Keyboard::Keyboard(GLFWwindow* window)
{
    nlohmann::json j;
    
    std::ifstream inputFile("res/Input/GLFW/Map_Keyboard.json");
    inputFile >> j;

    auto keyDataIn = j.get<std::vector<Gio::Input::Devices::KeyboardKeyData>>();

    for (int i= 0; i < keyDataIn.size(); i++)
    {
        auto keyData = keyDataIn[i];

        KeyboardKey* key = new KeyboardKey(keyData.name, keyData.type, keyData.glfwKeyID, window);
        
        elements.push_back(key);
    }
}

Gio::Input::Devices::Keyboard::~Keyboard()
{
}

Gio::Input::Devices::KeyboardKey* Gio::Input::Devices::Keyboard::GetKey(KeyboardKey::Types type)
{
    for (int i = 0; i < elements.size(); i++)
    {
        auto key = dynamic_cast<KeyboardKey*>(elements[i]);
        
        if(key->GetType() == type)
            return key;
    }

    return nullptr;
}