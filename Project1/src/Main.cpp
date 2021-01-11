#include "Camera.h"
#include "Debug.h"
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
    
    Transform& camTrans = Camera::GetTransform();
    
    auto camPos = camTrans.position;
    camPos.x = int((screenWidth/2));
    camPos.y = int((screenHeight/2));

    Debug::Log("New Cam pos will be" + camPos.to_string());
    
    camTrans.position = camPos;
    
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