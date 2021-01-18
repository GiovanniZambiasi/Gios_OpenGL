#include "Application.h"
#include "Debug.h"
#include "Time.h"
#include "Input/IInputDeviceFactory.h"
#include "Input/Input.h"
#include "Input/Factories/GLFWPCInputDeviceFactory.h"

Gio::Application::Application()
    : _window(nullptr)
      , _renderer(nullptr)
      , _game(nullptr)
      , _gui(nullptr)
      , _camera(nullptr)
      , _input(nullptr)
{
}

Gio::Application::~Application()
{
}

bool Gio::Application::Run(std::string name, unsigned int windowWidth, unsigned int windowHeight)
{
    _window = new Window();
    
    if (!_window->TryToInitialize(name.c_str(), windowWidth, windowHeight))
        return false;

    Input::IInputDeviceFactory* _inputDeviceFactory = new Input::Factories::GLFWPCInputDeviceFactory(_window->GetGLFWWindow()); // Determine current platform and create the factory
    
    _input = new Input::Input(*_inputDeviceFactory);
    
    _camera = new Camera();

    _renderer = new Renderer(_camera);
    
    //_window->onSizeChanged = HandleWindowSizeChanged;

    HandleWindowSizeChanged(windowWidth, windowHeight);
    
    _game = new Scene();

    _gui = new GUI(*_game, *_window, *_input);
    
    while (!_window->ShouldClose())
    {
        Time::RecordFrameTime();
        
        float deltaTime = Time::GetDeltaTimeSeconds();
        
        _gui->Clear();

        _renderer->Clear();
        
        _input->Update();
        
        _game->Update(deltaTime);

        _renderer->BeforeDraw();
        
        _game->Draw(*_renderer);

        _gui->Draw();
        
        _window->SwapBuffers();
    }

    return true;
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