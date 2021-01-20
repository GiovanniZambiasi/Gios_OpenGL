#include "Application.h"

#include "Debug.h"
#include "Time.h"
#include "InputSystem/IInputDeviceFactory.h"
#include "Input.h"
#include "InputSystem/Factories/GLFWPCInputDeviceFactory.h"

Gio::Application::Application(std::string name, unsigned int windowWidth, unsigned int windowHeight)
    : _scene(nullptr)
    , _gui(nullptr)
{
    _window = new Window(name.c_str(), windowWidth, windowHeight);

    if(!_window->GetIsValid())
    {
        return;
    }
}

Gio::Application::~Application()
{
}

bool Gio::Application::Run()
{
    if(!_window->GetIsValid())
        return false;

    InputSystem::IInputDeviceFactory* _inputDeviceFactory = new InputSystem::Factories::GLFWPCInputDeviceFactory(_window->GetGLFWWindow()); // Determine current platform and create the factory
    
    _input = new Input(*_inputDeviceFactory);
    
    _camera = new Camera();

    _renderer = new Renderer(_camera);

    _scene = new Scene();

    _gui = new GUI(*_scene, *_window, *_input);
    
    //_window->onSizeChanged = HandleWindowSizeChanged;

    HandleWindowSizeChanged(_window->GetWidth(), _window->GetHeight());
    
    while (!_window->ShouldClose())
    {
        try
        {
            Update();
        }
        catch(std::exception e)
        {
            Debug::LogError("Exception thrown during Update: '" + std::string(e.what()) + "'");
        }
    }

    return true;
}

void Gio::Application::Update()
{
    Time::RecordFrameTime();
        
    float deltaTime = Time::GetDeltaTimeSeconds();
        
    _gui->Clear();

    _renderer->Clear();
        
    _input->Update();
        
    _scene->Update(deltaTime);

    _renderer->BeforeDraw();
        
    _scene->Draw(*_renderer);

    _gui->Draw();
        
    _window->SwapBuffers();
}

void Gio::Application::HandleWindowSizeChanged(unsigned int width, unsigned int height)
{
    Debug::Log("Window size changed to: " + std::to_string(width) + "x" + std::to_string(height));

    _renderer->SetupProjectionMatrix(width, height);

    Transform& camTrans = _camera->GetTransform();
    
    auto camPos = camTrans.position;
    camPos.x = int((width/2));
    camPos.y = int((height/2));

    Debug::Log("Setting camPos to: " + camPos.to_string());
    
    camTrans.SetPosition(camPos);
}