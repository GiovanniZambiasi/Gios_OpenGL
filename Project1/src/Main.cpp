#include "Main.h"

#include "Debug.h"
#include "Input/Devices/KeyboardKeyData.h"

int main()
{
    Gio::Application application = Gio::Application();
    
    if(application.Run("Gio's OpenGL", 1240, 720))
    {
        return 0;
    }
    else
    {
        return 1;
    }
};