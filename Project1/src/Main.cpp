#include "Camera.h"
#include "Debug.h"
#include "Game.h"
#include "GUI.h"
#include "Renderer.h"
#include "Time.h"
#include "Window.h"

using namespace Gio;

int main()
{
    Window window;

    unsigned int screenWidth = 1240;
    unsigned int screenHeight = 720;
    
    if (!window.TryToInitialize("Gio's OpenGL", screenWidth, screenHeight))
        return -1;

    GUI::Initialize(window);
    
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

        GUI::Clear();
        
        Renderer::Clear();

        float deltaTime = Time::GetDeltaTimeSeconds();

        game.Update(deltaTime);

        Renderer::BeforeDraw();
        
        game.Draw();

        GUI::Draw();
        
        window.SwapBuffers();
    }

    GUI::Shutdown();

    return 0;
};