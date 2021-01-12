#include "Camera.h"
#include "Debug.h"
#include "Game.h"
#include "GUI.h"
#include "Renderer.h"
#include "Time.h"
#include "Window.h"
#include "Input/Input.h"
#include "Input/Key.h"

using namespace Gio;

void HandleWindowSizeChanged(unsigned int width, unsigned int height)
{
    Debug::Log("Window size changed to: " + std::to_string(width) + "x" + std::to_string(height));
    
    Renderer::SetupProjectionMatrix(width, height);

    Transform& camTrans = Camera::GetTransform();
    
    auto camPos = camTrans.position;
    camPos.x = int((width/2));
    camPos.y = int((height/2));

    Debug::Log("Setting camPos to: " + camPos.to_string());
    
    camTrans.SetPosition(camPos);
}

int main()
{
    Window* window = new Window();

    unsigned int screenWidth = 1240;
    unsigned int screenHeight = 720;
    
    if (!window->TryToInitialize("Gio's OpenGL", screenWidth, screenHeight))
        return -1;

    GUI::Initialize(*window);

    Input::Input::Initialize(*window);
    
    Camera::Initialize();

    window->onSizeChanged = HandleWindowSizeChanged;

    HandleWindowSizeChanged(screenWidth, screenHeight);
    
    Game* game = new Game();
    
    while (!window->ShouldClose())
    {
        if(Input::Input::GetKeyDown(Input::Key::Space))
        {
            Debug::Log("Space down");
        }
        
        Time::RecordFrameTime();
        
        GUI::Clear();
        
        Renderer::Clear();

        float deltaTime = Time::GetDeltaTimeSeconds();

        game->Update(deltaTime);

        Renderer::BeforeDraw();
        
        game->Draw();

        GUI::Draw();
        
        window->SwapBuffers();
    }

    GUI::Shutdown();

    return 0;
};