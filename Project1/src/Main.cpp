#include "Main.h"
#include "Application.h"

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