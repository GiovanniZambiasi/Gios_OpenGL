#include "Debug.h"
#include "Entity.h"
#include "Renderer.h"
#include "Time.h"
#include "Window.h"
#include "ECS/ObjectRenderer.h"

using namespace Gio;

int main()
{
    Window window;

    if (!window.TryToInitialize())
        return -1;

    Entity* _object = new Entity();

    std::vector<Vector2>* vec = new std::vector<Vector2>
    {
        Vector2(0.0f, .5f),
        Vector2(-.5f, -.5f),
        Vector2(.5f, -.5f),
    };

    auto renderer = new ECS::ObjectRenderer(_object->GetTransform(), vec, Color(1.0f, 0.0f, 0.0f, 1.0f));

    _object->AddComponent(renderer);
    
    while (!window.ShouldClose())
    {
        Time::RecordFrameTime();

        Debug::Log(
            std::to_string(Time::GetTimeSinceStartSeconds()) + " | DeltaTime: " +
            std::to_string(Time::GetDeltaTimeSeconds()) + " | FPS: " + std::to_string(Time::GetFPSApprox()));

        /* Render here */
        Renderer::Clear();

        float deltaTime = Time::GetTimeSinceStartSeconds();
        
        _object->Update(deltaTime);
        
        _object->LateUpdate(deltaTime);
        
        window.Update();
    }

    return 0;
};
