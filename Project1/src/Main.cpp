#include "Game.h"
#include "Renderer.h"
#include "Time.h"
#include "Window.h"

using namespace Gio;

int main()
{
    Window window;

    if (!window.TryToInitialize("Gio's OpenGL", 800, 600))
        return -1;

    Game game = Game();

    while (!window.ShouldClose())
    {
        Time::RecordFrameTime();
        
        /*Debug::Log(std::to_string(Time::GetTimeSinceStartSeconds()) + " | DeltaTime: " +
            std::to_string(Time::GetDeltaTimeSeconds()) + " | FPS: " + std::to_string(Time::GetFPSApprox())); */
        
        /* Render here */
        Renderer::Clear();

        float deltaTime = Time::GetDeltaTimeSeconds();

        game.Update(deltaTime);
        
        window.Update();
    }

    return 0;
};