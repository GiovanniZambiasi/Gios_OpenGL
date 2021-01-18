#include "Main.h"
#include "Application.h"
#include "Random.h"

int main()
{
    Gio::Application application = Gio::Application();

for (int i = 0; i < 100; i++)
{
        Gio::Debug::Log(std::to_string(Gio::Random::Between(10, 30)));
}
    
    
    if(application.Run("Gio's OpenGL", 1240, 720))
    {
        return 0;
    }
    else
    {
        return 1;
    }
};