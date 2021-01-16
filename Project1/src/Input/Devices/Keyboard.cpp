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
        
        _keys.push_back(key);
    }
}

Gio::Input::Devices::Keyboard::~Keyboard()
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey* key = _keys[i];
        
        delete key;
    }
}

void Gio::Input::Devices::Keyboard::Update()
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey* key = _keys[i];
        key->Update();
    }
}

void Gio::Input::Devices::Keyboard::GetElements(std::vector<IInputElement*>& elements)
{
    for (int i = 0; i < _keys.size(); i++)
    {
        KeyboardKey* key = _keys[i];
        elements.push_back(key);
    }
}

Gio::Input::Devices::KeyboardKey* Gio::Input::Devices::Keyboard::GetKey(KeyboardKey::Types type)
{
    for (int i =0; i < _keys.size(); i++)
    {
        auto key = _keys[i];
        if(key->GetType() == type)
            return key;
    }

    return nullptr;
}
