#include "Camera.h"
#include "Game.h"
#include "Renderer.h"
#include "Time.h"
#include "Window.h"

using namespace Gio;

int main()
{
    Window window;

    unsigned int screenWidth = 960;
    unsigned int screenHeight = 540;
    
    if (!window.TryToInitialize("Gio's OpenGL", screenWidth, screenHeight))
        return -1;

    Renderer::SetupProjectionMatrix(screenWidth, screenHeight);

    Camera::Initialize();
    
    Game game = Game();

    while (!window.ShouldClose())
    {
        Time::RecordFrameTime();
        
        /*Debug::Log(std::to_string(Time::GetTimeSinceStartSeconds()) + " | DeltaTime: " +
            std::to_string(Time::GetDeltaTimeSeconds()) + " | FPS: " + std::to_string(Time::GetFPSApprox())); */
        
        Renderer::Clear();

        float deltaTime = Time::GetDeltaTimeSeconds();

        game.Update(deltaTime);

        Renderer::BeforeDraw();
        
        game.Draw();
        
        window.SwapBuffers();
    }

    return 0;
};