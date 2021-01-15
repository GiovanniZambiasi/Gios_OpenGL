#include "Main.h"

int main()
{
    Gio::Application application = Gio::Application();

    Gio::Input::Devices::KeyboardKeyData keyData[] =
        {
        Gio::Input::Devices::KeyboardKeyData("Spacebar", Gio::Input::Devices::KeyboardKey::Space, 32),
        Gio::Input::Devices::KeyboardKeyData("Enter", Gio::Input::Devices::KeyboardKey::Enter, 12),
        };
    nlohmann::json j = keyData;
    
    std::string serialized = j.dump();

    std::ofstream file;
    file.open("res/Input/KeyboardMapping.json");
    file << serialized;
    file.close();
    
    if(application.Run("Gio's OpenGL", 1240, 720))
    {
        return 0;
    }
    else
    {
        return 1;
    }
};