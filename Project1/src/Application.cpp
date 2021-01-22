#include "Application.h"

#include "Debug.h"
#include "Time.h"
#include "InputSystem/IInputDeviceFactory.h"
#include "Input.h"
#include "InputSystem/Factories/GLFWPCInputDeviceFactory.h"

Gio::Application::Application(std::string name, unsigned int windowWidth, unsigned int windowHeight)
    : _renderer(nullptr)
      , _sceneManager(new SceneManager), _camera(nullptr), _input(nullptr), _gui(nullptr)
{
    _window = new Window(name.c_str(), windowWidth, windowHeight);
}

Gio::Application::~Application()
{
}

Gio::ApplicationResultTypes Gio::Application::Run()
{
    try
    {
        Prepare();
    }
    catch(std::exception e)
    {
        Debug::LogError("Exception caught while preparing scene: '" + std::string(e.what()) + "'");
    }
    
    while (!_window->ShouldClose())
    {
        try
        {
            Update();
        }
        catch(std::exception e)
        {
            Debug::LogError("Exception thrown during Update: '" + std::string(e.what()) + "'");
            return Bad;
        }
    }

    return Good;
}

void Gio::Application::Observe(WindowSize windowSize)
{
    Debug::Log("Window size changed to: " + windowSize.ToString());

    _renderer->SetupProjectionMatrix(windowSize);
}

void Gio::Application::Update()
{
    Time::RecordFrameTime();
        
    float deltaTime = Time::GetDeltaTimeSeconds();
        
    _gui->Clear();

    _renderer->Clear();
        
    _input->Update();

    _sceneManager->Update(deltaTime);
    
    _renderer->BeforeDraw();

    _sceneManager->Draw(*_renderer);

    _gui->Draw();
        
    _window->Update();
}

void Gio::Application::Prepare()
{
    if(!_window->GetIsValid())
    {
        throw BadWindowException();
    }

    InputSystem::IInputDeviceFactory* _inputDeviceFactory = new InputSystem::Factories::GLFWPCInputDeviceFactory(_window->GetGLFWWindow()); // Determine current platform and create the factory
    
    _input = new Input(*_inputDeviceFactory);
    
    _camera = new Camera();

    _renderer = new Renderer(_camera);

    _gui = new GUI(*_sceneManager, *_window, *_input, *_renderer);

    _sceneManager->CreateMasterScene();
    
    _window->onWindowSizeChanged.AddObserver(this);

    Observe(_window->GetSize());
}

char const* Gio::BadWindowException::what() const
{
    return "GLFW window is not valid";
}