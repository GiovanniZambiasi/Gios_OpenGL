#include "Main.h"
#include "Application.h"
#include "SceneManager.h"
#include "Example/SpaceScene.h"

int main()
{
    Gio::Application application = Gio::Application("Gio's OpenGL", 1240, 720);

    Gio::SceneManager::RegisterMasterScene<Gio::Example::SpaceScene>();
    
    auto result = application.Run();

    switch (result)
    {
    case Gio::Good:
        Gio::Debug::Log("Application has finished with status: GOOD");
        return 0;
    case Gio::Bad:
        Gio::Debug::LogError("Application has finished with status: BAD");
        return 1;
    default:
        Gio::Debug::LogError("Application has finished with uncaught status: " + result);
        return 1;
    }
}
