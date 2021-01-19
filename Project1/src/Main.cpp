#include "Main.h"
#include "Application.h"

int main()
{
    Gio::Application application = Gio::Application("Gio's OpenGL", 1240, 720);

    if(application.Run())
    {
        return 0;
    }
    else
    {
        return 1;
    }
};